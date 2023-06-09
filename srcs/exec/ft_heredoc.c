/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:18:30 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/06/09 11:33:07 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit2(int sig)
{
	(void)sig;
	write(1, "\n", 2);
	g_last_errno = 130;
	exit(130);
}

int	ft_heredoc(t_args *args, char *delimiter)
{
	char	*line;
	int		fd[2];
	pid_t	pid;

	args->heredoc = 0;
	signal(SIGINT, SIG_IGN);
	if (pipe(fd) == -1)
		return (ft_error(11));
	pid = fork();
	if (pid == -1)
		return (ft_error(10));
	if (pid == 0)
	{
		signal(SIGINT, ft_exit2);
		while (1)
		{
			line = readline("heredoc> ");
			if (line)
			{
				if (!ft_strcmp(line, delimiter))
				{
					args->heredoc = 1;
					break;
				}
				write(fd[1], line, ft_strlen(line));
				write(fd[1], "\n", 2);
				free(line);
			}
			else
			{
				write(1, "minishell: warning: here-document delimited by end-of-file\n", 60);
				args->heredoc = 1;
				break;
			}
		}
		exit(0);
	}
	close(fd[1]);
	args->infile = fd[0];
	waitpid(pid, NULL, 0);
	return (0);
}
