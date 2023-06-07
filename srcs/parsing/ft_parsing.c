/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:48:29 by ezanotti          #+#    #+#             */
/*   Updated: 2023/06/07 11:46:58 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_u(t_list *in)
{
	while (in)
	{
		printf("[%s]", (char *)in->content);
		in = in->next;
	}
	printf("\n");
}

void	ft_log(t_list *stack)
{
	while (stack)
	{
		ft_u(stack->content);
		stack = stack->next;
	}
	printf("%p\n", stack);
}

int	ft_parse_args(t_args *args, char *command)
{
	if (ft_split_quote(args, command))
		return (1);
	ft_u(args->command_list);
	if (ft_check_parsing(args))
		return (ft_free_instruction(args->command_list), 1);
	if (ft_get_stack(args))
		return (ft_free_instruction(args->command_list), 1);
	if (ft_parse_quotes(args))
	{
		ft_free_instruction(args->command_list);
		ft_free_stack(args->stack);
		return (1);
	}
	return (0);
}
