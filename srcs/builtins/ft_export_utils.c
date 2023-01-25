/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:02:29 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/25 18:03:17 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_value(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[1][i] && cmd[1][i] != '=')
		i++;
	return (cmd[1] + i + 1);
}

char	*ft_new_env(char *env)
{
	int		i;
	char	*new_env;

	new_env = malloc(sizeof(char) * (ft_strlen(env) + 1));
	i = 0;
	while (*env && *env != '+')
		new_env[i++] = *env++;
	if (*env)
	{
		env++;
		while (*env)
			new_env[i++] = *env++;
	}
	new_env[i] = '\0';
	return (new_env);
}
