/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstincrement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:07:56 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 15:25:21 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_lstincrement(t_list *instruction, int i)
{
	while (instruction && i-- > 0)
		instruction = instruction->next;
	return (instruction);
}
