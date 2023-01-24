/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event04 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:50:26 by event04           #+#    #+#             */
/*   Updated: 2023/01/24 16:21:07 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_remove_quote(char *str)
{
    char	*new_str;
    int		i;
    int		size;

	i = -1;
	size = 0;
	while (str[++i])
		if (str[i] == '\'' || str[i] == '"')
			size++;
	if (size == 0)
		return (str);
	new_str = malloc(sizeof(char) * (ft_strlen(str) - size + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str != '\'' && *str != '"')
			new_str[i++] = *str;
		str++;
	}
	new_str[i] = '\0';
    return (new_str);
}

static int	ft_get_size(char *str)
{
	char	*variable;
	int		i;
	int		size;

	size = 0;
	while (*str)
	{
		if (*str == '$')
		{
			i = 0;
			while (str[i] && str[i] != ' ' && str[i] != '\'' && str[i] != '"')
				i++;
			variable = ft_substr(str, 1, i++ - 1);
			if (!variable)
				return (-1);
			size += ft_strlen(getenv(variable)) - 1;
			free(variable);
			str += i - 2;
		}
		str++;
		size++;
	}
	return (size);
}

#include <string.h> // TODO remove after creating ft_strcat

char	*ft_replace_variable(char *new_str, char *str, int size)
{
	char	*variable;
	int		i;

	printf(">>> %s\n", str);

	while (*str)
	{
		if (*str == '$')
		{
			i = 0;
			while (str[i] && str[i] != ' ' && str[i] != '\'' && str[i] != '"')
				i++;
			variable = ft_substr(str, 1, i++ - 1);
			if (!variable)
				return (NULL);
			strcat(new_str, getenv(variable)); //TODO changer en ft_strcat
			size += ft_strlen(getenv(variable));
			free(variable);
			str += i - 2;
		}
		else if (*str != '"')
			new_str[size++] = *str;
		str++;
	}
	new_str[size] = '\0';
	return (new_str);
}

char	*ft_replace_env(char *str)
{
	char	*new_str;
	int		size;

	size = ft_get_size(str);
	if (str[0] == '"' && str[ft_strlen(str) - 1] == '"')
		size -= 2;
	if (size < 0)
		return (NULL);
	new_str = malloc(sizeof(char) * (size + 1));
	if (!new_str)
		return (NULL);
	new_str[0] = '\0';
	new_str = ft_replace_variable(new_str, str, 0);
	return (new_str);
}

int	ft_parse_quotes(t_args *args)
{
	char	*current;
	int		i;
	int		j;

	i = -1;
	while (args->stack[++i])
	{
		j = -1;
		while (args->stack[i][++j])
		{
			current = args->stack[i][j];
			if (current[0] != '\'' && \
				current[ft_strlen(current)] != '\'')
				current = ft_replace_env(current);
			if (!current)
				return (ft_error(99));
			current = ft_remove_quote(current);
			args->stack[i][j] = current;
			if (!args->stack[i][j])
				return (ft_error(99));
		}
	}
	return (0);
}
