/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:24:09 by elias             #+#    #+#             */
/*   Updated: 2023/02/28 11:21:15 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_parsing(t_args *args)
{
	t_list	*cl;

	cl = args->cl;
	if (!cl)
		return (1);
	if (ft_is_delimiter(cl) == '|')
		return (ft_error(4));
	while (cl)
	{
		if (ft_is_delimiter(cl) && !cl->next)
			return (ft_error(6));
		if (ft_is_delimiter(cl) == '|' && cl->next)
			if (ft_is_delimiter(cl->next) == '|')
				return (ft_error(4));
		if (ft_is_redirect(cl) && cl->next)
			if (ft_is_delimiter(cl->next))
				return (ft_error(5));
		cl = cl->next;
	}
	return (0);
}

int	ft_check_command(t_args *args)
{
	t_list	*stack;

	stack = args->stack;
	while (stack && stack->content)
	{
		if (!ft_is_delimiter(stack->content) && \
			!ft_is_command(args, stack->content) && \
			!ft_is_builtins(stack->content))
			return (ft_error(2));
		stack = stack->next;
	}
	return (0);
}
