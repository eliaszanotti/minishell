/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envpnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:57:11 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 14:57:26 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_envp	*ft_envpnew(char *name, char *value, int equal)
{
	t_envp	*envp;

	envp = malloc(sizeof(t_envp));
	if (!envp)
		return (NULL);
	envp->name = name;
	envp->value = value;
	envp->equal = equal;
	envp->next = NULL;
	return (envp);
}