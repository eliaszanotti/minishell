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

char	*ft_skip_single_dollar(t_list **instruction, char *str)
{
	if (*str == '$' && (!str[1] || str[1] == '$'))
	{
		if (ft_add_single_str(instruction, "$"))
			return (NULL);
		return (str + 1);
	}
	return (str);
}

char	*ft_skip_error(t_list **instruction, char *str)
{
	char	*error;

	if (*str == '$' && str[1] && str[1] == '?')
	{
		error = ft_itoa(g_last_errno);
		if (!error)
			return (NULL);
		if (ft_add_single_str(instruction, error))
			return (NULL);
		free(error);
		return (str + 2);
	}
	return (str);
}

static int	ft_add_each_variable(t_list **instruction, char *value)
{
	char	**values;
	t_list	*new;
	int		i;

	values = ft_split(value, ' ');
	if (!values)
		return (ft_error(99));
	i = 0;
	while (values[i])
	{
		new = ft_lstnew(ft_strdup(values[i]));
		if (!new)
			return (ft_free_str(values), ft_error(99));
		ft_lstadd_back(instruction, new);
		i++;
	}
	return (ft_free_str(values), 0);
}

static char	*ft_skip_variable(t_args *args, t_list **instruction, char *str)
{
	char	*name;
	char	*value;
	int		i;

	i = 0;
	if (*str == '$' && str[1] && str[1] != '$')
	{
		str++;
		while (str[i] && ft_is_variable(str[i]))
			i++;
		name = ft_substr(str, 0, i);
		if (!name)
			return (NULL);
		value = ft_getenv(args, name);
		free(name);
		if (!value)
			return (str + i);
		if (ft_add_each_variable(instruction, value))
			return (free(value), NULL);
		return (free(value), str + i);
	}
	return (str);
}

char	*ft_skip_expand(t_args *args, t_list **instruction, char *str)
{
	str = ft_skip_single_dollar(instruction, str);
	if (!str)
		return (NULL);
	str	= ft_skip_error(instruction, str);	
	if (!str)
		return (NULL);
	str = ft_skip_variable(args, instruction, str);
	if (!str)
		return (NULL);
	return (str);
}
