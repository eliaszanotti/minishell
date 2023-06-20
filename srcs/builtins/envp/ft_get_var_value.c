/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_var_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:05:06 by elias             #+#    #+#             */
/*   Updated: 2023/06/20 18:44:17 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
