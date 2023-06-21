/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:03:48 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/06/21 11:17:59 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_var(char *var)
{
	int	i;

	i = -1;
	if (var[0] && var[0] == '-')
		return (ft_error(25, NULL));
	if (!var[0] || ft_isdigit(var[0]))
		return (ft_error(14, NULL));
	while (var[++i])
	{
		if (!ft_isalnum(var[i]) && var[i] != '_')
			return (ft_error(14, NULL));
	}
	return (0);
}

static int	ft_remove_var(t_args *args, char *var)
{
	t_envp	*envp;
	t_envp	*backup;

	envp = args->envp;
	ft_check_var(var);
	while (envp)
	{
		if (!ft_strcmp(envp->name, var))
		{
			backup->next = envp->next;
			free(envp->name);
			free(envp->value);
			free(envp);
			break ;
		}
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
