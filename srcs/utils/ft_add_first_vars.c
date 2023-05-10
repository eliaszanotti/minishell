/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_first_vars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:12:16 by elias             #+#    #+#             */
/*   Updated: 2023/05/10 19:20:39 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_add_to_envp(t_args *args, char *name, char *value)
{
	t_envp	*new;

	new = ft_envpnew(name, value, 1);
	if (!new)
		return (ft_error(99));
	ft_envpadd_back(&args->envp, new);
	return (0);
}

int	ft_add_first_vars(t_args *args)
{
	char	*cwd;
	t_envp	*envp;

	cwd = getcwd(NULL, 0);
	envp = args->envp;	
	while (envp && ft_strcmp(envp->name, "SHLVL"))
		envp = envp->next;
	if (!envp)
		ft_add_to_envp(args, ft_strdup("SHLVL"), ft_strdup("1"));
	envp = args->envp;	
	while (envp && ft_strcmp(envp->name, "PWD"))
		envp = envp->next;
	if (!envp)
		ft_add_to_envp(args, ft_strdup("PWD"), ft_strdup(cwd));
	envp = args->envp;	
	while (envp && ft_strcmp(envp->name, "_"))
		envp = envp->next;
	if (!envp)
		ft_add_to_envp(args, ft_strdup("_"), ft_strdup("/usr/bin/env"));
	return (0);
}
