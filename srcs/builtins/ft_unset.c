/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:03:48 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/26 17:19:00 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO unset ne marche pas

void ft_ll(char **env)
{
	while (*env)
	{
		printf(">> %s\n", *env);
		env++;
	}
}

int	ft_unset(char **cmd, t_args *args)
{
	char	**new_envp;
	int		i;
	
	i = 0;
	while (cmd[++i])
	{
		new_envp = ft_get_new_envp(args, cmd[i]);
		//ft_ll(new_envp);
		args->envp = new_envp;
		if (!args->envp)
			return (ft_error(99));
		// TODO free new_envp
	}
	return (0);
}
