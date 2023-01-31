/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_char_envp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:02:36 by elias             #+#    #+#             */
/*   Updated: 2023/01/31 18:54:21 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_name_and_value(char *name, char *value)
{
	char	*str;

	str = ft_strjoin(name, "=");
	str = ft_strjoin(str, value);
	return (str);
}

char	**ft_get_char_envp(t_args *args)
{
	t_envp	*envp;
	char	**new_envp;
	int		i;

	i = ft_envpsize(args->envp);
	new_envp = malloc(sizeof(char *) * (i + 1));
	if (!new_envp)
		return (NULL);
	i = 0;
	envp = args->envp;
	while (envp)
	{
		new_envp[i++] = ft_get_name_and_value(envp->name, envp->value);
		envp = envp->next;
	}
	new_envp[i] = NULL;
	return (new_envp);
}
