/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:03:48 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/26 18:46:36 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(char **cmd, t_args *args)
{
	char	**new_envp;
	int		i;
	
	i = 0;
	while (cmd[++i])
	{
		new_envp = ft_remove_var(args, cmd[i]);
		//ft_ll(new_envp);
		args->envp = new_envp;
		if (!args->envp)
			return (ft_error(99));
		// TODO free new_envp
	}
	return (0);
}
