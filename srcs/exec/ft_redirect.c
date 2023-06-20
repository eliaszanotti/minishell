/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:27:22 by elias             #+#    #+#             */
/*   Updated: 2023/06/20 17:05:34 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_redirect(t_list *instruction, t_args *args)
{
	t_list	*next;

	next = instruction->next;
	if (ft_is_delimiter(instruction) == '<')
		args->infile = open(next->content, O_RDONLY);
	else if (ft_is_delimiter(instruction) == '>')
		args->outfile = open(next->content, O_RDWR | O_TRUNC | O_CREAT, 0644);
	else if (ft_is_delimiter(instruction) == 'r')
		args->outfile = open(next->content, O_RDWR | O_APPEND | O_CREAT, 0644);
	else if (ft_is_delimiter(instruction) == 'l' && \
		(ft_heredoc(args, next->content) || args->heredoc_stop))
		return (1);
	if (args->infile == -1)
		ft_error(10, NULL);
	if (args->outfile == -1)
		return (ft_error(11, NULL));
	return (0);
}
