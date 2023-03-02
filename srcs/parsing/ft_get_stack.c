/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:21:53 by elias             #+#    #+#             */
/*   Updated: 2023/03/02 15:28:05 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_stack(t_args *args, int j)
{
	t_list	*command_list;
	t_list	*new;

	command_list = args->command_list;
	while (command_list)
	{
		j = 0;
		if (ft_is_delimiter(command_list) == '|')
		{
			new = ft_lstnew(ft_lstcopy(command_list, 1));
			if (!new)
				return (ft_error(99));
			ft_lstadd_back(&args->stack, new);
			command_list = command_list->next;
		}
		while (ft_lstincrement(command_list, j) && \
			ft_is_delimiter(ft_lstincrement(command_list, j)) != '|')
			j++;
		if (ft_add_redirects(args, command_list, j + 1))
			return (ft_error(99));
		if (ft_add_command(args, command_list, j + 1))
			return (ft_error(99));
		command_list = ft_lstincrement(command_list, j);
	}
	return (0);
}
