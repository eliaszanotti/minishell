/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:58:52 by elias             #+#    #+#             */
/*   Updated: 2023/01/31 18:54:03 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(t_args *args, char *name)
{
	t_envp	*envp;

	if (!name)
		return (NULL);
	envp = args->envp;
	while (envp && ft_strcmp(name, envp->name))
		envp = envp->next;
	if (envp)
		return (ft_strdup(envp->value));
	return (NULL);
}
