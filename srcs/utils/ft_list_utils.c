/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_increment_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:35:22 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/10 16:39:01 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_increment_list(t_list *instruction, int i)
{
	while (instruction && i-- > 0)
		instruction = instruction->next;
	return (instruction);
}

t_list	*ft_cpy(t_list *new, int j)
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
