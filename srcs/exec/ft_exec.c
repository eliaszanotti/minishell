/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:30:39 by elias             #+#    #+#             */
/*   Updated: 2023/02/10 17:52:59 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_dup_and_exec(t_args *args, char **command, int last, int fd[2])
{
	//char	**char_envp;
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
	if (ft_is_builtins(command[0]) && !ft_exec_builtins(args, command))
		exit(0);
	path = ft_get_path(args, command[0]);
	//char_envp = ft_get_char_envp(args);
	printf("PATH = %s\n\n", path);
	if (execve(path, command, args->char_envp) == -1)
		return (free(path), ft_error(12));
	//ft_free_str(char_envp);
	free(path);
	return (0);
}

void	ft_looo(char **log)
{
	while (*log)
		printf("l = [%s]\n", *log++);	
}

void	ft_in(t_list *list)
{
	char *str;
	while (list)
	{
		str = list->content;
		printf("log = %s\n", str);
		list = list->next;
	}
}

static int	ft_execute_child(t_args *args, char **command, int last)
{
	int		fd[2];
	pid_t	pid;

	ft_looo(command);
	if (pipe(fd))
		return (ft_error(11));
	if (last && args->size == 1 && ft_is_builtins(command[0]))
		return (ft_exec_builtins(args, command));
	pid = fork();
	if (pid == -1)
		return (ft_error(4));
	args->char_envp = ft_get_char_envp(args);
	if (pid == 0 && ft_dup_and_exec(args, command, last, fd))
	{
		ft_free_str(args->char_envp);
		exit(0);
		return (1);
	}
	ft_free_str(args->char_envp);
	close(fd[1]);
	ft_add_pid(args, pid);
	args->infile = STDIN_FILENO;
	args->outfile = STDOUT_FILENO;
	args->fdd = fd[0];
	return (0);
}

int	ft_r(t_list *instruction, t_args *args)
{
	t_list	*next;

	next = instruction->next;
	if (ft_is_d(instruction) == '<')
		args->infile = open(next->content, O_RDONLY);
	else if (ft_is_d(instruction) == '>')
		args->outfile = open(next->content, O_RDWR | O_TRUNC | O_CREAT, 0644);
	else if (ft_is_d(instruction) == 'r')
		args->outfile = open(next->content, O_RDWR | O_APPEND | O_CREAT, 0644);
	else if (ft_is_d(instruction) == 'l' && ft_heredoc(args, next->content))
		return (1);
	if (args->infile == -1) 
		return (ft_error(14));
	if (args->outfile == -1)
		return (ft_error(15));
	return (0);
}

char	**ft_get_instruction(t_list *instruction)
{
	char	**char_instruction;
	int		size;

	ft_in(instruction);
	size = ft_lstsize(instruction) + 1;
	char_instruction = malloc(sizeof(char *) * size);
	if (!char_instruction)
		return (NULL);
	size = 0;
	while (instruction)
	{
		char_instruction[size++] = instruction->content;
		instruction = instruction->next;	
	}
	char_instruction[size] = NULL;
	return (char_instruction);
}

static int	ft_execute_command(t_args *args, int count)
{
	char	**instruction;
	t_list	*stack;

	stack = args->stack_list;
	while (stack && count < args->size - 1)
	{	
		if (ft_is_r(stack->content) && ft_r(stack->content, args))
			return (1);
		else if (ft_is_c(args, stack->content) || ft_is_b(stack->content))
		{
			instruction = ft_get_instruction(stack->content); // TODO free
			if (!instruction)
				return (ft_error(99));
			if (ft_execute_child(args, instruction, 0))
				return (1);
			count++;
		}
		stack = stack->next;
	}
	if (ft_is_d(stack->content) == '|')
		stack = stack->next;
	while (stack && ft_is_r(stack->content))
	{
		if (ft_r(stack->content, args))
			return (1);
		stack = stack->next;
	}
	instruction = ft_get_instruction(stack->content); // TODO free
	printf("febhf\n");
	ft_looo(instruction);
	if (!instruction)
		return (ft_error(99));
	if (stack && ft_execute_child(args, instruction, 1))
		return (1);
	return (0);
}

int	ft_start_execution(t_args *args)
{
	t_list	*stack;
	int		i;

	stack = args->stack_list;
	i = -1;
	while (stack)
	{
		if (ft_is_b(stack->content) || ft_is_c(args, stack->content))
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
	if (ft_execute_command(args, 0))
		return (free(args->pid_tab), 1);
	return (ft_wait_execution(args));
}
