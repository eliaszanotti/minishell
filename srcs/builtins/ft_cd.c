/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:00:59 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/06/21 11:41:31 by tgiraudo         ###   ########.fr       */
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
		args->equal = 1;
		if (ft_add_var_to_envp(args, ft_strdup("OLDPWD"), ft_strdup(pwd), 0))
			return (1);
	}
	return (0);
}

static int	ft_update_pwds(t_args *args)
{
	char	cwd[PATH_MAX];

	getcwd(cwd, sizeof(cwd));
	if (ft_change_oldpwd(args))
		return (1);
	if (ft_add_var_to_envp(args, ft_strdup("PWD"), ft_strdup(cwd), 0))
		return (1);
	return (0);
}

int	ft_cd(t_args *args, char **cmd)
{
	char	*env;	

	env = ft_getenv(args, "HOME");
	if (cmd[2])
		return (free(env), ft_error(15, NULL));
	if (cmd[1])
	{
		if (cmd[1][0] == '-')
			return (free(env), ft_error(25, NULL));
		if (chdir(cmd[1]) == -1)
			return (free(env), ft_error(12, NULL));
		if (ft_update_pwds(args))
			return (free(env), 1);
	}
	else if (chdir(env) == -1)
		return (free(env), ft_error(12, NULL));
	else
	{
		if (ft_update_pwds(args))
			return (free(env), 1);
	}
	return (free(env), 0);
}
