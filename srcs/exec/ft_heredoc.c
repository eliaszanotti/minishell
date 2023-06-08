/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:18:30 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/06/07 18:27:19 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit2(int sig)
{
	(void)sig;
	write(1, "\n", 2);
	exit(0);
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
					break ;
				}
				write(fd[1], line, ft_strlen(line));
				write(fd[1], "\n", 2);
				free(line);
			}
			else
			{
				write(1, "\nminishell: warning: here-document delimited by end-of-file\n", 60);
				args->heredoc = 1;
				break ;
			}
		}
	}
	close(fd[1]);
	waitpid(pid, NULL, 1);
	args->infile = fd[0];
	return (0);
}
