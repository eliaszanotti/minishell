/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:57:08 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/16 14:51:18 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ilstadd_back(t_ilst **lst, t_ilst *new)
{
	t_ilst	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_ilstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}
