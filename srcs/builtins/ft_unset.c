/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:03:48 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/31 17:04:10 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_remove_var(t_args *args, char *var)
{
	t_envp	*envp;
	t_envp	*backup;

	envp = args->envp2;
	while (envp)
	{
		if (!ft_strcmp(envp->name, var))
			backup->next = envp->next;
		backup = envp;
		envp = envp->next;
	}
	return (0);
}

int	ft_unset(t_args *args, char **cmd)
{
	int		i;

	i = 0;
	while (cmd[++i])
		if (ft_remove_var(args, cmd[i]))
			return (1);
	return (0);
}
