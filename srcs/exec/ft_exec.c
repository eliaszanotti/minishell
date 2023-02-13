/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:30:39 by elias             #+#    #+#             */
/*   Updated: 2023/02/13 18:07:41 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_dup_and_exec(t_args *args, char **command, int last, int fd[2])
{
	char	**char_envp;
	char	*path;

	if (args->infile && dup2(args->infile, STDIN_FILENO) == -1)
		return (ft_error(13));
	else if (dup2(args->fdd, STDIN_FILENO) == -1)
		return (ft_error(13));
	if (!last && dup2(fd[1], STDOUT_FILENO) == -1)
		return (ft_error(13));
	if (args->outfile && dup2(args->outfile, STDOUT_FILENO) == -1)
		return (ft_error(13));
	close(fd[0]);
	if (ft_is_char_builtins(command[0]) && !ft_exec_builtins(args, command))
		exit(0);
	path = ft_get_path(args, command[0]);
	char_envp = ft_get_char_envp(args);
	if (execve(path, command, char_envp) == -1)
		return (ft_free_str(char_envp), free(path), ft_error(12));
	ft_free_str(char_envp);
	free(path);
	return (0);
}

static int	ft_execute_child(t_args *args, char **command, int last)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd))
		return (ft_error(11));
	if (last && args->size == 1 && ft_is_char_builtins(command[0]))
		return (ft_exec_builtins(args, command));
	pid = fork();
	if (pid == -1)
		return (ft_error(4));
	if (pid == 0 && ft_dup_and_exec(args, command, last, fd))
		return (1);
	close(fd[1]);
	ft_add_pid(args, pid);
	args->infile = STDIN_FILENO;
	args->outfile = STDOUT_FILENO;
	args->fdd = fd[0];
	return (0);
}

char	**ft_get_instruction(t_list *instruction)
{
	char	**char_instruction;
	int		size;

	size = ft_lstsize(instruction) + 1;
	char_instruction = malloc(sizeof(char *) * size);
	if (!char_instruction)
		return (NULL);
	size = 0;
	while (instruction)
	{
		char_instruction[size++] = ft_strdup(instruction->content);
		instruction = instruction->next;
	}
	char_instruction[size] = NULL;
	return (char_instruction);
}

static t_list	*ft_execute_loop(t_args *args, t_list *stack)
{
	char	**instruction;
	t_list	*current;
	int		count;

	current = stack;
	count = 0;
	while (current && count < args->size - 1)
	{	
		if (ft_is_redirect(current->content) && \
			ft_redirect(current->content, args))
			return (NULL);
		else if (ft_is_command(args, current->content) || \
			ft_is_builtins(current->content))
		{
			instruction = ft_get_instruction(current->content);
			if (!instruction)
				return (NULL);
			if (ft_execute_child(args, instruction, 0))
				return (ft_free_str(instruction), NULL);
			ft_free_str(instruction);
			count++;
		}
		current = current->next;
	}
	return (current);
}

static int	ft_execute_command(t_args *args)
{
	char	**instruction;
	t_list	*stack;

	stack = ft_execute_loop(args, args->stack);
	if (!stack)
		return (1);
	if (ft_is_delimiter(stack->content) == '|')
		stack = stack->next;
	while (stack && ft_is_redirect(stack->content))
	{
		if (ft_redirect(stack->content, args))
			return (1);
		stack = stack->next;
	}
	instruction = ft_get_instruction(stack->content);
	if (!instruction)
		return (ft_error(99));
	if (stack && ft_execute_child(args, instruction, 1))
		return (ft_free_str(instruction), 1);
	return (ft_free_str(instruction), 0);
}

int	ft_start_execution(t_args *args)
{
	t_list	*stack;
	int		i;

	stack = args->stack;
	i = -1;
	while (stack)
	{
		if (ft_is_builtins(stack->content) || \
			ft_is_command(args, stack->content))
			args->size++;
		stack = stack->next;
	}
	i = 0;
	args->pid_tab = malloc(sizeof(pid_t) * args->size);
	if (!args->pid_tab)
		return (free(args->pid_tab), ft_error(99));
	while (i < args->size)
		args->pid_tab[i++] = 0;
	args->fdd = 0;
	if (ft_execute_command(args))
		return (free(args->pid_tab), 1);
	return (ft_wait_execution(args));
}
