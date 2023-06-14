/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:21:53 by elias             #+#    #+#             */
/*   Updated: 2023/06/14 12:46:32 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*ft_add_pipe(t_args *args, t_list *command_list)
{
	t_list	*new;

	if (ft_is_delimiter(command_list) == '|')
	{
		new = ft_lstnew(ft_lstcopy(command_list, 1));
		if (!new)
			return (NULL);
		ft_lstadd_back(&args->stack, new);
		command_list = command_list->next;
	}
	return (command_list);
}

int	ft_get_stack(t_args *args)
{
	t_list	*command_list;
	int		j;

	command_list = args->command_list;
	while (command_list)
	{
		j = 0;
		command_list = ft_add_pipe(args, command_list);
		if (!command_list)
			return (ft_error(99, NULL));
		while (ft_lstincrement(command_list, j) && \
			ft_is_delimiter(ft_lstincrement(command_list, j)) != '|')
			j++;
		if (ft_add_redirects(args, command_list, j + 1))
			return (ft_error(99, NULL));
		if (ft_add_command(args, command_list, j + 1))
			return (ft_error(99, NULL));
		command_list = ft_lstincrement(command_list, j);
	}
	return (0);
}
