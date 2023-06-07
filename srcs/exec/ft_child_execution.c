/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:44:24 by ezanotti          #+#    #+#             */
/*   Updated: 2023/06/07 16:06:06 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_duplicate_all_fd(t_args *args, int last, int fd[2])
{
	close(fd[0]);
	if (args->infile == -1)
		exit(1);
	if (args->infile && dup2(args->infile, STDIN_FILENO) == -1)
		return (ft_error(13));
	else if (dup2(args->fdd, STDIN_FILENO) == -1)
		return (ft_error(13));
	if (!last && dup2(fd[1], STDOUT_FILENO) == -1)
		return (ft_error(13));
	if (args->outfile && dup2(args->outfile, STDOUT_FILENO) == -1)
		return (ft_error(13));
	return (0);
}

static int	ft_dup_and_exec(t_args *args, char **command, int last, int fd[2])
{
	char	**char_envp;
	char	*path;

	if (ft_duplicate_all_fd(args, last, fd))
		return (1);
	args->last = last;
	if (ft_is_char_builtins(command[0]) && !ft_exec_builtins(args, command))
		exit(errno);
	path = ft_get_path(args, command[0]);
	if (!path)
		exit(ft_error_command(command[0]));
	char_envp = ft_get_char_envp(args);
	execve(path, command, char_envp);
	ft_free_str(char_envp);
	free(path);
	exit(ft_error(12));
	return (0);
}

static int	ft_exec_child_builtins(t_args *args, char **command, int last)
{
	if (ft_is_char_builtins(command[0]))
	{
		if (args->size > 1)
		{
			if (last && ft_strcmp(command[0], "cd") && ft_strcmp(command[0], "exit") && ft_strcmp(command[0], "unset"))
				return (ft_exec_builtins(args, command));
			return (0);
		}
		return (ft_exec_builtins(args, command));
	}
	return (0);
}

int	ft_execute_child(t_args *args, char **command, int last)
{
	char	*path;
	int		fd[2];
	pid_t	pid;

	signal(SIGQUIT, ft_quit);
	signal(SIGINT, ft_sign);
	g_last_errno = 0;
	if (pipe(fd))
		return (ft_error(11));
	if (ft_exec_child_builtins(args, command, last))
		return (1);
	pid = fork();
	if (pid == -1)
		return (ft_error(4));
	if (pid == 0 && ft_dup_and_exec(args, command, last, fd))
		return (1);
	path = ft_get_path(args, command[0]);
	if (!path)
		g_last_errno = 127;
	close(fd[1]);
	ft_add_pid(args, pid);
	args->infile = STDIN_FILENO;
	args->outfile = STDOUT_FILENO;
	args->fdd = fd[0];
	return (free(path), 0);
}
