/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:44:24 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/08 17:58:05 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_dup_and_exec(t_args *args, char **command, int last, int fd[2])
{
	char	**char_envp;
	char	*path;

	close(fd[0]);
	if (args->infile && dup2(args->infile, STDIN_FILENO) == -1)
		return (ft_error(13));
	else if (dup2(args->fdd, STDIN_FILENO) == -1)
		return (ft_error(13));
	if (!last && dup2(fd[1], STDOUT_FILENO) == -1)
		return (ft_error(13));
	if (args->outfile && dup2(args->outfile, STDOUT_FILENO) == -1)
		return (ft_error(13));
	if (ft_is_char_builtins(command[0]) && !ft_exec_builtins(args, command))
		exit(errno);
	path = ft_get_path(args, command[0]);
	char_envp = ft_get_char_envp(args);
	if (execve(path, command, char_envp) == -1)
	{
		ft_free_str(char_envp);
		free(path);
		exit(ft_error(12));
	}
	return (0);
}

int	ft_execute_child(t_args *args, char **command, int last)
{
	int		fd[2];
	pid_t	pid;

	signal(SIGINT, ft_sign);
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
