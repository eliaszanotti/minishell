/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:05:06 by elias             #+#    #+#             */
/*   Updated: 2023/05/10 19:10:03 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_variable(char c)
{
	char	*var;

	var = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789?_";
	while (*var)
		if (c == *var++)
			return (1);
	return (0);
}

char	*ft_get_var_name(char *var, int *add)
{
	int	i;

	i = -1;
	while (var[++i])
		if (ft_strchr("#%?!@/-+={}.,:", var[i]))
			return (ft_error(23), NULL);
	if (ft_isdigit(var[0]))
		return (ft_error(23), NULL);
	while (var[i] && ft_is_variable(var[i]))
		i++;
	if (var[i] == '+' && var[i + 1] == '=')
	{
		*add = 1;
		return (ft_substr(var, 0, i));
	}
	return (ft_substr(var, 0, i));
}

char	*ft_get_var_value(t_args *args, char *var)
{
	int	i;

	args->equal = 1;
	i = 0;
	while (var[i] && ft_is_variable(var[i]))
		i++;
	if (var[i] == '+' && var[i + 1] == '=')
		return (ft_substr(var, i + 2, ft_strlen(var) - i - 1));
	if (var[i] == '=')
		return (ft_substr(var, i + 1, ft_strlen(var) - i));
	args->equal = 0;
	return (ft_strdup("\0"));
}
