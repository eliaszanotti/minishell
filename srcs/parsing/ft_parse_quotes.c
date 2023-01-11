/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event04 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:50:26 by event04           #+#    #+#             */
/*   Updated: 2023/01/11 13:05:27 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
				return (0); //TODO change to strerror
			size += ft_strlen(getenv(variable)) - 1;
			free(variable);
			str += i - 2;
		}
		str++;
		size++;
	}
	return (size - 2);
}

#include <string.h> // TODO remove after creating ft_strcat

char	*ft_replace_env(char *str)
{
	char	*new_str;
	char	*variable;
	int		size;
	int		i;

	size = ft_get_size(str);
	new_str = malloc(sizeof(char) * (size + 1));
	if (!new_str)
		return (NULL);
	new_str[0] = '\0';
	size = 0;
	i = 0;
	while (*++str)
	{
		if (*str == '$')
		{
			i = 0;
			while (str[i] && str[i] != ' ' && str[i] != '\'' && str[i] != '"')
				i++;
			variable = ft_substr(str, 1, i++ - 1);
			if (!variable)
				return (0); //TODO change to strerror
			strcat(new_str, getenv(variable)); //TODO changer en ft_strcat (qui nexite pas pour le moment lol)
			size += ft_strlen(getenv(variable));
			free(variable);
			str += i - 2;
		}
		else if (*str != '"')
			new_str[size++] = *str;
	}
	//free(str); //TODO sert a rien vu que str est vide a ce moment la (str++ fait qu'il devient vide)
	new_str[size] = '\0';
	return (new_str);
}

int	ft_parse_quotes(t_args *args)
{
	char	*current;
	int		i;
	int		j;
	int		len;

	i = -1;
	while (args->stack[++i])
	{
		j = -1;
		while (args->stack[i][++j])
		{
			current = args->stack[i][j];
			len = ft_strlen(current) - 1;
			if (current[0] == '"' && current[len] == '"')
				current = ft_replace_env(current);
			else if (current[0] == '\'' && current[len] == '\'')
				current = ft_substr(current, 1, len - 1);
			args->stack[i][j] = current;
			if (!args->stack[i][j])
				return (99);
		}
	}
	return (0);
}
