/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:18:30 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/26 12:57:55 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_heredoc(char *delimiter, t_args *args)
{
	char	*line;
	int		fd[2];

	if (pipe(fd) == -1)
		return ;
	while (1)
	{
		line = readline("heredoc> ");
		if (!ft_strcmp(line, delimiter))
			break ;
		write(fd[1], line, ft_strlen(line));
		write(fd[1], "\n", 1);
		free(line);
	}
	args->infile = fd[0];
	close(fd[1]);
	ft_start_execution(args);
}
