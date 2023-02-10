/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:24:09 by elias             #+#    #+#             */
/*   Updated: 2023/02/10 11:52:03 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**ft_get_command_list(t_list *instruction)
{
	char	**command_list;
	int		size;

	size = ft_lstsize(instruction) + 1;
	command_list = malloc(sizeof(char *) * size);
	if (!command_list)
		return (NULL);
	size = 0;
	while (instruction)
	{
		command_list[size++] = instruction->content;
		instruction = instruction->next;
	}
	command_list[size] = NULL;
	return (command_list);
}

int	ft_check_parsing(t_args *args)
{
	char	**command_list;
	int		i;

	command_list = ft_get_command_list(args->cl);
	if (!command_list && !*command_list)
		return (1);
	i = -1;
	if (ft_is_delimiter(*command_list) == '|')
		return (ft_free_str(command_list), ft_error(4));
	while (command_list[++i])
	{
		if (ft_is_delimiter(command_list[i]) && !command_list[i + 1])
			return (ft_free_str(command_list), ft_error(6));
		if (ft_is_delimiter(command_list[i]) == '|' && command_list[i + 1])
			if (ft_is_delimiter(command_list[i + 1]) == '|')
				return (ft_free_str(command_list), ft_error(4));
		if (ft_is_redirect(command_list[i]) && command_list[i + 1])
			if (ft_is_delimiter(command_list[i + 1]))
				return (ft_free_str(command_list), ft_error(5));
	}
	return (ft_free_str(command_list), 0);
}

int	ft_check_command(t_args *args)
{
	t_list	*stack;
	t_list	*tmp;

	stack = args->stack_list;
	while (stack)
	{
		tmp = stack->content;
		if (tmp && (!ft_is_delimiter(tmp->content) && \
			!ft_is_command(args, tmp->content) && 
			!ft_is_builtins(tmp->content)))
			return (ft_error(2));
		stack = stack->next;
	}
	return (0);
}
