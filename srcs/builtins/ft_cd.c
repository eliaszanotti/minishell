/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:00:59 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/06/14 13:45:51 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_change_oldpwd(t_args *args)
{
	t_envp	*envp;
	char	*pwd;

	envp = args->envp;
	while (envp && ft_strcmp(envp->name, "PWD"))
		envp = envp->next;
	if (envp)
	{
		pwd = envp->value;
		if (ft_add_var_to_envp(args, ft_strdup("OLDPWD"), ft_strdup(pwd), 0))
			return (1);
	}
	return (0);
}

int	ft_cd(t_args *args, char **cmd)
{
	char	*env;	
	char	cwd[PATH_MAX];

	env = ft_getenv(args, "HOME");
	if (cmd[1])
	{
		if (chdir(cmd[1]) == -1)
			return (free(env), ft_error(12, NULL));
		getcwd(cwd, sizeof(cwd));
		if (ft_change_oldpwd(args))
			return (1);
		if (ft_add_var_to_envp(args, ft_strdup("PWD"), ft_strdup(cwd), 0))
			return (free(env), 1);
	}
	else if (chdir(env) == -1)
		return (free(env), ft_error(12, NULL));
	else
	{
		getcwd(cwd, sizeof(cwd));
		if (ft_change_oldpwd(args))
			return (1);
		if (ft_add_var_to_envp(args, ft_strdup("PWD"), ft_strdup(cwd), 0))
			return (free(env), 1);
	}
	return (free(env), 0);
}
