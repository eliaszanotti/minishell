/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:48:42 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 15:25:57 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_instruction(t_list *instruction)
{
	t_list	*tmp;

	while (instruction)
	{
		free(instruction->content);
		tmp = instruction->next;
		free(instruction);
		instruction = tmp;
	}
}
