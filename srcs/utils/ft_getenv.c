/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:58:52 by elias             #+#    #+#             */
/*   Updated: 2023/01/31 17:12:21 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(t_args *args, char *name)
{
	t_envp	*envp;

	if (!name)
		return (NULL);
	envp = args->envp2;
	while (envp && ft_strcmp(name, envp->name))
		envp = envp->next;
	if (envp)
		return (ft_strdup(envp->value));
	return (NULL);
	/*while (args->envp[++i])
	{
		j = 0;
		while (args->envp[i][j] && args->envp[i][j] != '=')
			j++;
		if (args->envp[i][j] == '=')
			current = ft_substr(args->envp[i], 0, j);
		if (!current)
			return (NULL);
		if (!ft_strcmp(current, variable))
		{
			free(current);
			return (ft_substr(args->envp[i], \
				j + 1, ft_strlen(args->envp[i]) - j - 1));
		}
		free(current);
	}
	return (NULL);*/
}
