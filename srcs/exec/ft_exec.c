/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:30:39 by elias             #+#    #+#             */
/*   Updated: 2023/02/01 11:20:06 by elias            ###   ########.fr       */
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
	if (ft_is_builtins(command[0]) && !ft_exec_builtins(args, command))
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
	if (last && args->size == 1 && ft_is_builtins(command[0]))
		return (ft_exec_builtins(args, command));
	pid = fork();
	if (pid == -1)
		return (ft_error(4));
	else if (pid == 0 && ft_dup_and_exec(args, command, last, fd))
		return (1);
	close(fd[1]);
	ft_add_pid(args, pid);
	args->infile = STDIN_FILENO;
	args->outfile = STDOUT_FILENO;
	args->fdd = fd[0];
	return (0);
}

static int	ft_execute_command(t_args *args, int count)
{
	int	i;

	i = -1;
	while (args->stack[++i] && count < args->size - 1)
	{	
		if (ft_is_redirect(args->stack[i][0]) && \
			ft_redirect(args->stack[i], args))
			return (1);
		else if (ft_is_command(args, args->stack[i][0]) || \
			ft_is_builtins(args->stack[i][0]))
		{
			if (ft_execute_child(args, args->stack[i], 0))
				return (1);
			count++;
		}
	}
	if (ft_is_delimiter(args->stack[i][0]) == '|')
		i++;
	while (args->stack[i] && ft_is_redirect(args->stack[i][0]))
		if (ft_redirect(args->stack[i++], args))
			return (1);
	if (args->stack[i] && ft_execute_child(args, args->stack[i], 1))
		return (1);
	return (0);
}

int	ft_start_execution(t_args *args)
{
	int	i;

	i = -1;
	while (args->stack[++i])
		if (ft_is_builtins(args->stack[i][0]) || \
			ft_is_command(args, args->stack[i][0]))
			args->size++;
	i = 0;
	args->pid_tab = malloc(sizeof(pid_t) * args->size);
	if (!args->pid_tab)
		return (free(args->pid_tab), ft_error(99));
	while (i < args->size)
		args->pid_tab[i++] = 0;
	args->fdd = 0;
	if (ft_execute_command(args, 0))
		return (free(args->pid_tab), 1);
	if (ft_wait_execution(args))
		return (free(args->pid_tab), 1);
	return (free(args->pid_tab), 0);
}
