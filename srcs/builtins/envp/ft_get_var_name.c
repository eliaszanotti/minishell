/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_var_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:39:13 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 15:24:41 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_var_name(char *var, int *add)
{
	int	i;

	i = 0;
	if (ft_isdigit(var[0]))
		return (ft_error(23), NULL);
	while (var[i] && ft_is_variable(var[i]))
		i++;
	if (var[i] && var[i] != '=' && var[i] != '+' && !ft_is_variable(var[i]))
		return (ft_error(23), ft_strdup("\0"));
	if (var[i] == '+' && var[i + 1] == '=')
	{
		*add = 1;
		return (ft_substr(var, 0, i));
	}
	return (ft_substr(var, 0, i));
}
