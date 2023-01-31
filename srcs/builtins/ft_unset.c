/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:03:48 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/31 11:52:33 by elias            ###   ########.fr       */
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
		//ft_free_str(args->envp);
		//ft_free_str(new_envp);
		if (!new_envp)
			return (ft_error(99));
		ft_free_str(args->envp);
		args->envp = new_envp;
		//ft_free_str(new_envp);
		// TODO free new_envp
	}
	//ll(args->envp);
	return (0);
}
