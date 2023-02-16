/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:51:08 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/16 14:51:48 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ilstadd_front(t_ilst **lst, t_ilst *new)
{
	if (!lst)
		return ;
	if (*lst)
		new->next = *lst;
	*lst = new;
}
