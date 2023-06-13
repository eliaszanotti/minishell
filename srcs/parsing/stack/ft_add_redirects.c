/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:03:44 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 15:22:43 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_add_redirects(t_args *args, t_list *instruction, int max)
{
	t_list	*new;

	while (--max > 0 && instruction)
	{
		if (ft_is_delimiter(instruction) && instruction->next)
		{
			new = ft_lstnew(ft_lstcopy(instruction, 2));
			if (!new)
				return (ft_error(99));
			ft_lstadd_back(&args->stack, new);
			instruction = instruction->next;
			max--;
		}
		instruction = instruction->next;
	}
	return (0);
}
