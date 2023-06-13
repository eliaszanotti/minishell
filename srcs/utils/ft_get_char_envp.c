/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_char_envp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:02:36 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 15:03:15 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_get_name_and_value(char *name, char *value)
{
	char	*str;
	char	*tmp;

	tmp = ft_strjoin(name, "=");
	str = ft_strjoin(tmp, value);
	free(tmp);
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
