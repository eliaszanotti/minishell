/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:48:45 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 13:57:36 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_add_str_to_new_list(t_list *list, t_list **new_list, int size)
{
	char	*str;
	char	*content;

	str = malloc(sizeof(char) * size);
	if (!str)
		return (ft_error(99));
	size = 0;
	while (list && list->content)
	{
		content = list->content;
		while (*content)
			str[size++] = *content++;
		list = list->next;
	}
	str[size] = '\0';
	list = ft_lstnew(str);
	if (!list)
		return (ft_error(99));
	ft_lstadd_back(new_list, list);
	return (0);
}

static int	ft_remove_current_chain(t_list **list, t_list **new_list)
{
	t_list	*list_copy;
	t_list	*temp;
	int		size;

	list_copy = *list;
	if (!list_copy->content)
	{
		*list = list_copy->next;
		return (0);
	}
	size = 1;
	while (list_copy && list_copy->content)
	{
		size += ft_strlen(list_copy->content);
		list_copy = list_copy->next;
	}
	temp = *list;
	*list = list_copy;
	list_copy = temp;
	if (size > 1 && ft_add_str_to_new_list(list_copy, new_list, size))
		return (ft_error(99));
	return (0);
}

int	ft_remove_null(t_args *args)
{
	t_list	*command_list;
	t_list	*new_list;

	command_list = args->command_list;
	new_list = NULL;
	while (command_list)
	{
		if (ft_remove_current_chain(&command_list, &new_list))
			return (ft_error(99));
	}
	ft_free_instruction(args->command_list);
	args->command_list = new_list;
	return (0);
}
