/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:29:17 by elias             #+#    #+#             */
/*   Updated: 2023/02/28 11:20:39 by ezanotti         ###   ########.fr       */
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

static int	ft_add_instruction_to_stack(t_args *args, t_list *instruction)
{
	t_list	*new;

	if (instruction)
	{
		new = ft_lstnew(instruction);
		if (!new)
			return (ft_error(99));
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
				return (ft_error(99));
			ft_lstadd_back(&instruction, new);
			cmd = cmd->next;
		}
	}
	return (ft_add_instruction_to_stack(args, instruction));
}
