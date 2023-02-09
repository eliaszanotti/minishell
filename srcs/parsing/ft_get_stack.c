/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:21:53 by elias             #+#    #+#             */
/*   Updated: 2023/02/09 18:31:36 by ezanotti         ###   ########.fr       */
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

t_list	*ft_copy_stack(char **command_list, int j)
{
	t_list	*instruction;
	t_list	*new;
	int		i;

	instruction = NULL;
	i = 0;
	while (command_list[i] && i < j)
	{
		new = ft_lstnew(command_list[i++]);
		if (!new)
			return (NULL);
		ft_lstadd_back(&instruction, new);
	}
	return (instruction);
}

int	ft_get_stack(t_args *args, int j)
{
	char	**command_list;
	t_list	*new;

	command_list = args->command_list;
	args->stack_list = NULL; // TODO move si error nrm
	while (*command_list)
	{
		if (ft_is_delimiter(*command_list) == '|')
		{
			new = ft_lstnew(ft_copy_stack(command_list++, 1));
			if (!new || !new->content)
				return (ft_error(99)); //TODO free si error
			ft_lstadd_back(&args->stack_list, new);
		}
		while (command_list[j] && ft_is_delimiter(command_list[j]) != '|')
			j++;
		if (ft_add_redirects(args, command_list, j + 1))
			return (ft_error(99));
		if (ft_add_command(args, command_list, j + 1))
			return (ft_error(99));
		command_list += j;
	}
	ll(args);
	return (0);
}
