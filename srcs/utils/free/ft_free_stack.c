/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:49:20 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 15:26:01 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_stack(t_list *stack)
{
	t_list	*tmp;

	while (stack)
	{
		ft_free_instruction(stack->content);
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
