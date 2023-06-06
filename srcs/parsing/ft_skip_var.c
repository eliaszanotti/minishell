/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:56:10 by elias             #+#    #+#             */
/*   Updated: 2023/06/06 13:56:33 by elias            ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_add_new_list(t_list **instruction, t_list *new_list)
{
	char	*content;
	char	*new_str;
	t_list	*list;
	int		size;
	int		i;

	new_str = malloc(sizeof(char) * (ft_get_list_size(new_list) + 1));
	if (!new_str)
		return (ft_error(99));
	size = 0;
	list = new_list;
	while (list)
	{
		i = 0;
		content = list->content;
		while (content[i])
			new_str[size++] = content[i++];
		list = list->next;
	}
	new_str[size] = '\0';
	list = ft_lstnew(new_str);
	if (!list)
		return (free(new_str), ft_error(99));
	ft_lstadd_back(instruction, list);
	return (0);
}

static int	ft_add_current_value(t_list **new_list, char **values, int i)
{
	t_list	*new;

	new = ft_lstnew(ft_strdup(values[i]));
	if (!new)
		return (ft_error(99));
	ft_lstadd_back(new_list, new);
	if (values[i + 1] && ft_add_single_str(new_list, " "))
		return (ft_error(99));
	return (0);
}

static int	ft_add_each_variable(t_list **instruction, t_list *list)
{
	char	**values;
	t_list	*new_list;
	int		i;

	new_list = NULL;
	while (list)
	{
		values = ft_split(list->content, ' ');
		if (!values)
			return (ft_error(99));
		i = 0;
		while (values[i])
		{
			if (ft_add_current_value(&new_list, values, i++))
				return (ft_free_str(values), ft_error(99));
		}
		list = list->next;
	}
	if (ft_add_new_list(instruction, new_list))
		return (ft_error(99));
	return (0);
}

static char	*ft_skip_current_var(t_args *args, t_list **list, char *str)
{
	char	*name;
	char	*value;
	t_list	*new;
	int		i;

	i = 0;
	while (str[i] && (ft_is_variable(str[i]) || str[i] == '$'))
	{
		str++;
		while (str[i] && ft_is_variable(str[i]))
			i++;
		if (!i)
			return (str);
		name = ft_substr(str, 0, i);
		if (!name)
			return (NULL);
		value = ft_getenv(args, name);
		free(name);
		if (!value)
			return (str + i);
		new = ft_lstnew(value);
		if (!new)
			return (NULL);
		ft_lstadd_back(list, new);
		str += i;
	}
	return (str);
}

char	*ft_skip_variable(t_args *args, t_list **instruction, char *str)
{
	t_list	*list;

	list = NULL;
	if (*str == '$' && !str[1] && ft_add_single_str(instruction, "$"))
		return (NULL);
	if (*str == '$' && str[1] != '?')
	{
		str = ft_skip_current_var(args, &list, str);
		if (ft_add_each_variable(instruction, list))
			return (NULL);
		return (str);
	}
	return (str);
}
