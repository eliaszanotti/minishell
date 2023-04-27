/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:00:59 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/04/27 13:57:16 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(t_args *args, char **cmd)
{
	char	*env;	
	char	cwd[PATH_MAX];

	env = ft_getenv(args, "HOME");
	if (cmd[1])
	{
		if (chdir(cmd[1]) == -1)
			return (free(env), ft_error(20));
		getcwd(cwd, sizeof(cwd));
		if (ft_add_var_to_envp(args, ft_strdup("PWD"), ft_strdup(cwd), 0))
			return (free(env), 1);
	}
	else if (chdir(env) == -1)
		return (free(env), ft_error(20));
	else
	{
		getcwd(cwd, sizeof(cwd));
		if (ft_add_var_to_envp(args, ft_strdup("PWD"), ft_strdup(cwd), 0))
			return (free(env), 1);
	}
	return (free(env), 0);
}
