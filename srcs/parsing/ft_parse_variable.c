/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_variable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:28:37 by elias             #+#    #+#             */
/*   Updated: 2023/02/15 17:58:31 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_get_variable_size(t_args *args, char *str, int *size)
{
	char	*variable;
	char	*env;
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\'' && str[i] != '"')
		i++;
	variable = ft_substr(str, 1, i++ - 1);
	if (!variable)
		return (NULL);
	env = ft_getenv(args, variable);
	if (env)
		*size += ft_strlen(env);
	free(env);
	free(variable);
	str += i - 2;
	return (str);
}

static int	ft_get_size(t_args *args, char *str)
{
	int		size;

	size = 0;
	while (*str)
	{
		if (*str == '$')
		{
			str = ft_get_variable_size(args, str, &size);
			if (!str)
				return (-1);
		}
		else
			size++;
		str++;
	}
	return (size);
}

static char	*ft_current_var(t_args *args, char *new_str, char *str, int *size)
{
	char	*variable;
	char	*env;
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\'' && str[i] != '"')
		i++;
	variable = ft_substr(str, 1, i++ - 1);
	if (!variable)
		return (NULL);
	env = ft_getenv(args, variable);
	if (env)
	{
		new_str = ft_strcat(new_str, env);
		*size += ft_strlen(env);
	}
	free(env);
	free(variable);
	str += i - 1;
	return (str);
}

static char	*ft_replace_variable(t_args *args, char *new_str, char *str)
{
	int	size;

	size = 0;
	while (*str)
	{
		if (*str == '$')
		{
			str = ft_current_var(args, new_str, str, &size);
			if (!str)
				return (NULL);
		}
		else
			new_str[size++] = *str++;
	}
	new_str[size] = '\0';
	return (new_str);
}

char	*ft_replace_env(t_args *args, char *str)
{
	char	*new_str;
	int		size;

	size = ft_get_size(args, str);
	if (size == -1)
		return (NULL);
	if (str[0] == '"' && str[ft_strlen(str) - 1] == '"')
	{
		size -= 2;
		str[ft_strlen(str) - 1] = '\0';
		str++;
	}
	new_str = malloc(sizeof(char) * (size + 1));
	if (!new_str)
		return (NULL);
	while (size >= 0)
		new_str[size--] = '\0';
	new_str = ft_replace_variable(args, new_str, str);
	return (new_str);
}
