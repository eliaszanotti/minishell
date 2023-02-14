/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:21:53 by elias             #+#    #+#             */
/*   Updated: 2023/02/14 15:45:35 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_stack(t_args *args, int j)
{
	t_list	*cl;
	t_list	*new;

	cl = args->cl;
	while (cl)
	{
		j = 0;
		if (ft_is_delimiter(cl) == '|')
		{
			new = ft_lstnew(ft_lstcopy(cl, 1));
			if (!new)
				return (ft_error(99));
			ft_lstadd_back(&args->stack, new);
			cl = cl->next;
		}
		while (ft_lstincrement(cl, j) && \
			ft_is_delimiter(ft_lstincrement(cl, j)) != '|')
			j++;
		if (ft_add_redirects(args, cl, j + 1))
			return (ft_error(99));
		if (ft_add_command(args, cl, j + 1))
			return (ft_error(99));
		cl = ft_lstincrement(cl, j);
	}
	return (0);
}
