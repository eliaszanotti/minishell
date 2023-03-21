/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:03:41 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/21 18:20:54 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_quotes(char *s)
{
	char	quote;
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			quote = s[i++];
			while (s[i] && s[i] != quote)
				i++;
			if (!s[i])
				return (1);
		}
		i++;
	}
	return (0);
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
	if (*str == '$' && str[1] != '?')
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

int	ft_split_quote(t_args *args, char *str)
{
	if (!str || !*str)
		return (1);
	if (ft_check_quotes(str))
		return (ft_error(3));
	args->command_list = NULL;
	while (*str)
	{
		str = ft_skip_redirect(&args->command_list, str);
		if (!str)
			return (ft_error(99));
		str = ft_skip_alpha(&args->command_list, str);
		if (!str)
			return (ft_error(99));
		str = ft_skip_variable(args, &args->command_list, str);
		if (!str)
			return (ft_error(99));
		str = ft_skip_pipe(&args->command_list, str);
		if (!str)
			return (ft_error(99));
		str = ft_skip_spaces(str);
	}
	return (0);
}
