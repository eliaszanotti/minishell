/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:30:39 by elias             #+#    #+#             */
/*   Updated: 2023/01/25 14:57:30 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_dup_and_exec(t_args *args, char **command, int last, int fd[2])
{
	if (args->infile && dup2(args->infile, STDIN_FILENO) == -1)
		return (ft_error(13));
	else if (dup2(args->fdd, STDIN_FILENO) == -1)
		return (ft_error(13));
	if (!last && dup2(fd[1], STDOUT_FILENO) == -1)
		return (ft_error(13));
	if (args->outfile && dup2(args->outfile, STDOUT_FILENO) == -1)
		return (ft_error(13));
	close(fd[0]);
	if (execve(ft_get_path(command[0]), command, args->envp) == -1)
		return (ft_error(12));
	return (0);
}

int ft_execute_child(t_args *args, char **command, int last)
{
	int fd[2];
	pid_t pid;

	if (pipe(fd))
		return (ft_error(11));
	if (!ft_exec_builtins(args))
	{
		pid = fork();
		if (pid == -1) 
			return (ft_error(4));
		else if (pid == 0 && ft_dup_and_exec(args, command, last, fd))
			return (1);
		close(fd[1]);
		waitpid(pid, NULL, 0);
	}
	args->infile = STDIN_FILENO;
	args->outfile = STDOUT_FILENO;
	args->fdd = fd[0];
	return (0);
}

int	ft_execute_command(t_args *args, int size)
{
	int	count;
	int i;
	args->fdd = 0;

	count = 0;
	i = -1;
	while (args->stack[++i] && count < size - 1)
	{
		if (!ft_get_path(args->stack[i][0]) && \
			ft_is_delimiter(args->stack[i][0]) != '|' && \
			ft_redirect(args->stack[i], args))
			return (1);
		else if (ft_get_path(args->stack[i][0]))
		{
			if (ft_execute_child(args, args->stack[i], 0))
				return (1);
			count++;
		}
	}
	if (ft_is_delimiter(args->stack[i][0]) == '|')
		i++;
	while (!ft_get_path(args->stack[i][0]) && \
		ft_is_delimiter(args->stack[i][0]) != '|' && \
		!ft_is_builtins(args->stack[i][0]))
		if (ft_redirect(args->stack[i++], args))
			return (1);
	if (ft_execute_child(args, args->stack[i], 1))
		return (1);
	return (0);
}

int	ft_start_execution(t_args *args)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (args->stack[i])
		if (ft_get_path(args->stack[i++][0]))
			size++;
	return (ft_execute_command(args, size));
}
