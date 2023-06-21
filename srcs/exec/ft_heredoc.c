/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:49:08 by elias             #+#    #+#             */
/*   Updated: 2023/06/21 16:11:07 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_free_heredoc(t_args *args, int fd[2])
{
	t_envp	*envp;

	envp = args->envp;
	close(fd[0]);
	close(fd[1]);
	free(args->pid_tab);
	free(args->close_tab);
	while (envp && ft_strcmp(envp->name, "SHLVL"))
		envp = envp->next;
	if (envp)
		free(envp->value);
	// ft_free_envp(args);
	ft_free_stack(args->stack);
	// ft_free_stack(args->command_list);
	if (g_last_errno == 130)
		exit(130);
}

static void	ft_exit_heredoc(int sig)
{
	(void)sig;
	write(1, "\n", 2);
	close(0);
	g_last_errno = 130;
}

static int	ft_heredoc_loop(t_args *args, char *delimiter, int fd[2])
{
	char	*line;

	while (1)
	{
		line = readline("heredoc> ");
		if (line)
		{
			if (!ft_strcmp(line, delimiter))
			{	
				free(line);
				ft_free_heredoc(args, fd);
				break ;
			}
			write(fd[1], line, ft_strlen(line));
			write(fd[1], "\n", 2);
			free(line);
		}
		else
		{
			ft_free_heredoc(args, fd);
			write(1, "minishell: warning: here-document"\
				" delimited by end-of-file\n", 60);
			break ;
		}
	}
	return (0);
}

int	ft_heredoc(t_args *args, char *delimiter)
{
	int		fd[2];
	int		ret;
	pid_t	pid;

	signal(SIGINT, SIG_IGN);
	if (pipe(fd) == -1)
		return (ft_error(11, NULL));
	pid = fork();
	if (pid == -1)
		return (ft_error(1260, NULL));
	if (pid == 0)
	{
		g_last_errno = 0;
		signal(SIGINT, ft_exit_heredoc);
		if (ft_heredoc_loop(args, delimiter, fd))
			return (1);
		close(fd[1]);
		// close(fd[0]);
		exit(0);
	}
	// printf("closing fd[%d]\n", fd[1]);
	close(fd[1]);
	args->fdd = fd[0];
	waitpid(pid, &ret, 0);
	g_last_errno = WEXITSTATUS(ret);
	if (g_last_errno == 130)
		args->heredoc_stop = 1;
	return (0);
}
