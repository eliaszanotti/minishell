/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chained_envp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:52:40 by elias             #+#    #+#             */
/*   Updated: 2023/03/21 17:21:46 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_envpsize(t_envp *envp)
{
	int	count;

	count = 0;
	while (envp)
	{
		envp = envp->next;
		count++;
	}
	return (count);
}

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
