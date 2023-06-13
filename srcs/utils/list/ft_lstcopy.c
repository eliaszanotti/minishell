/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:35:22 by ezanotti          #+#    #+#             */
/*   Updated: 2023/06/13 15:09:24 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_lstcopy(t_list *new, int j)
{
	t_list	*instruction;
	t_list	*cpy;

	instruction = NULL;
	while (new && j > 0)
	{
		cpy = ft_lstnew(new->content);
		if (!cpy)
			return (NULL);
		ft_lstadd_back(&instruction, cpy);
		new = new->next;
		j--;
	}
	return (instruction);
}
