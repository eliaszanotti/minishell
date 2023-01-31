/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:52:40 by elias             #+#    #+#             */
/*   Updated: 2023/01/31 14:59:13 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_envp	*ft_envpnew(char *name, char *value)
{
	t_envp	*envp;

	envp = malloc(sizeof(t_envp));
	if (!envp)
		return (NULL);
	envp->name = name;
	envp->value = value;
	envp->next = NULL;
	return (envp);
}

t_envp	*ft_envplast(t_envp *envp)
{
	while (envp)
	{
		if (!envp->next)
			return (envp);
		envp = envp->next;
	}
	return (envp);
}

void	ft_envpadd_back(t_envp **lst, t_envp *new)
{
	t_envp	*last;

	if (!lst)
		return ;
	if (*lst)
	{
		last = ft_envplast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}
