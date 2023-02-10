/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:29:17 by elias             #+#    #+#             */
/*   Updated: 2023/02/10 12:46:53 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_add_redirects(t_args *args, char **cmd, int max)
{
	t_list	*new;

	while (--max > 0 && *cmd)
	{
		if (ft_is_delimiter(*cmd) && cmd[1])
		{
			new = ft_lstnew(ft_copy_stack(cmd, 2));
			if (!new)
				return (ft_error(99));
			ft_lstadd_back(&args->stack_list, new);
			max--;
		}
		cmd++;
	}
	return (0);
}

int	ft_add_command(t_args *args, char **cmd, int max)
{
	t_list	*instruction;
	t_list	*new;

	instruction = NULL;
	while (--max > 0 && *cmd)
	{
		if (ft_is_delimiter(*cmd) && cmd[1])
		{
			cmd += 2;
			max--;
		}
		else
		{
			new = ft_lstnew(*cmd++);
			if (!new)
				return (ft_error(99));
			ft_lstadd_back(&instruction, new);
		}
	}
	new = ft_lstnew(instruction);
	if (!new)
		return (ft_error(99));
	ft_lstadd_back(&args->stack_list, new);
	return (0);
}
