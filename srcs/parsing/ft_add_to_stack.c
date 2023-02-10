/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:29:17 by elias             #+#    #+#             */
/*   Updated: 2023/02/10 16:34:44 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_add_redirects(t_args *args, t_list *instruction, int max)
{
	t_list	*new;

	while (--max > 0 && instruction)
	{
		if (ft_is_d(instruction) && instruction->next)
		{
			new = ft_lstnew(ft_cpy(instruction, 2));
			if (!new)
				return (ft_error(99));
			ft_lstadd_back(&args->stack_list, new);
			instruction = instruction->next;
			max--;
		}
		instruction = instruction->next;
	}
	return (0);
}

int	ft_add_command(t_args *args, t_list *cmd, int max)
{
	t_list	*instruction;
	t_list	*new;

	instruction = NULL;
	while (--max > 0 && cmd)
	{
		if (ft_is_d(cmd) && cmd->next)
		{
			cmd = ft_increment_list(cmd, 2);
			max--;
		}
		else
		{
			new = ft_cpy(cmd, 1);
			if (!new)
				return (ft_error(99));
			ft_lstadd_back(&instruction, new);
			cmd = cmd->next;
		}
	}
	new = ft_lstnew(instruction);
	if (!new)
		return (ft_error(99));
	ft_lstadd_back(&args->stack_list, new);
	return (0);
}
