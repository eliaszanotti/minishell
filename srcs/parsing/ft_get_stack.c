/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:21:53 by elias             #+#    #+#             */
/*   Updated: 2023/02/10 16:40:46 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdio.h>
void ll(t_args *args)
{
	t_list	*stack;
	t_list	*instruction;
	char	*str;
	stack = args->stack_list;
	while (stack)
	{
		instruction = stack->content;
		while (instruction)
		{
			str = instruction->content;
			printf("[%s]", str);
			instruction = instruction->next;
		}
		printf("\n");
		stack = stack->next;
	}
}

void	ft_log(t_list *list)
{
	char *str;
	while (list)
	{
		str = list->content;
		printf("log = %s\n", str);
		list = list->next;
	}
}

int	ft_get_stack(t_args *args, int j)
{
	t_list	*cl;
	t_list	*new;

	cl = args->cl;
	args->stack_list = NULL; // TODO move si error nrm
	while (cl)
	{
		if (ft_is_d(cl) == '|')
		{
			new = ft_lstnew(ft_cpy(cl, 1));
			if (!new)
				return (ft_error(99));
			ft_lstadd_back(&args->stack_list, new);
			cl = cl->next;
		}
		while (ft_increment_list(cl, j) && \
			ft_is_d(ft_increment_list(cl, j)) != '|')
			j++;
		if (ft_add_redirects(args, cl, j + 1))
			return (ft_error(99));
		if (ft_add_command(args, cl, j + 1))
			return (ft_error(99));
		cl = ft_increment_list(cl, j);
	}
	ll(args);
	return (0);
}
