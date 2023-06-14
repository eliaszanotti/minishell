/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:04:19 by elias             #+#    #+#             */
/*   Updated: 2023/06/14 12:46:11 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_add_instruction_to_stack(t_args *args, t_list *instruction)
{
	t_list	*new;

	if (instruction)
	{
		new = ft_lstnew(instruction);
		if (!new)
			return (ft_error(99, NULL));
		ft_lstadd_back(&args->stack, new);
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
		if (ft_is_delimiter(cmd) && cmd->next)
		{
			cmd = ft_lstincrement(cmd, 2);
			max--;
		}
		else
		{
			new = ft_lstcopy(cmd, 1);
			if (!new)
				return (ft_error(99, NULL));
			ft_lstadd_back(&instruction, new);
			cmd = cmd->next;
		}
	}
	return (ft_add_instruction_to_stack(args, instruction));
}
