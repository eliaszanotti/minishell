/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:27:22 by elias             #+#    #+#             */
/*   Updated: 2023/06/09 13:47:21 by elias            ###   ########.fr       */
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
		ft_error(14);
	if (args->outfile == -1)
		return (ft_error(15));
	return (0);
}
