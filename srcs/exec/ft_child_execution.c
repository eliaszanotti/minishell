/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:44:24 by ezanotti          #+#    #+#             */
/*   Updated: 2023/06/21 09:51:33 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_exec_child_builtins(t_args *args, char **command, int last)
{
	if (!ft_strcmp(command[0], "exit") || \
		!ft_strcmp(command[0], "cd") || \
		!ft_strcmp(command[0], "unset"))
		return (0);
	if (!last && (!ft_strcmp(command[0], "env") || \
		!ft_strcmp(command[0], "pwd") || !ft_strcmp(command[0], "export") || \
		!ft_strcmp(command[0], "echo")))
		return (ft_exec_builtins(args, command), 0);
	if (last)
		return (ft_exec_builtins(args, command), 0);
	return (ft_exec_builtins(args, command), 1);
}

static int	ft_duplicate_all_fd(t_args *args, int last, int fd[2])
{
	close(fd[0]);
	if (args->infile == -1)
		exit(1);
	if (args->infile && dup2(args->infile, STDIN_FILENO) == -1)
		return (ft_error(1263, NULL));
	if (!args->infile && dup2(args->fdd, STDIN_FILENO) == -1)
		return (ft_error(1263, NULL));
	if (!last && dup2(fd[1], STDOUT_FILENO) == -1)
		return (ft_error(1263, NULL));
	if (args->outfile && dup2(args->outfile, STDOUT_FILENO) == -1)
		return (ft_error(1263, NULL));
	return (0);
}

static int	ft_dup_and_exec(t_args *args, char **command, int last, int fd[2])
{
	char	**char_envp;
	char	*path;

	signal(SIGQUIT, ft_signals);
	signal(SIGINT, ft_signals);
	args->last = last;
	if (ft_duplicate_all_fd(args, last, fd))
		return (1);
	if (ft_is_char_builtins(command[0]) && \
		!ft_exec_child_builtins(args, command, last))
			exit(g_last_errno);
	path = ft_get_path(args, command[0]);
	if (!path)
		exit(ft_error(1270, command[0]));
	if (ft_check_stat(path))
		exit(ft_error(1264, command[0]));
	char_envp = ft_get_char_envp(args);
	execve(path, command, char_envp);
	ft_free_str(char_envp);
	free(path);
	exit(ft_error(1262, NULL));
	return (0);
}

int	ft_child_execution(t_args *args, char **command, int last)
{
	char	*path;
	int		fd[2];
	pid_t	pid;

	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	if (pipe(fd))
		return (ft_error(1261, NULL));
	if (args->size == 1 && ft_is_char_builtins(command[0]))
		return (ft_exec_builtins(args, command));
	g_last_errno = 0;
	pid = fork();
	if (pid == -1)
		return (ft_error(1260, NULL));
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
