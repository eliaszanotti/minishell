/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:18:30 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/02/01 10:49:19 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_heredoc(t_args *args, char *delimiter)
{
	char	*line;
	int		fd[2];

	if (pipe(fd) == -1)
		return (ft_error(11));
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
	return (0);
}
