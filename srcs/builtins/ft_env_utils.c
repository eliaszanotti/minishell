/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:05:06 by elias             #+#    #+#             */
/*   Updated: 2023/01/30 19:32:44 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_var_name(char *variable)
{
	int		i;

	i = 0;
	while (variable[i] && variable[i] != '=')
		i++;
	if (variable[i] == '=')
		return (ft_substr(variable, 0, i));
	return (NULL);
}

int	ft_get_envp_size(char **envp)
{
	int	size;

	size = 0;
	while (envp[size])
		size++;
	return (size);
}

static char	**ft_remove_env_var(t_args *args, char **new_envp, char *variable)
{
	char	*current;
	int		i;
	int		i_tab;

	i = -1;
	i_tab = 0;
	while (args->envp[++i])
	{
		current = ft_get_var_name(args->envp[i]);
		if (ft_strcmp(current, variable))
			new_envp[i_tab++] = ft_strdup(args->envp[i]);
		free(current);
	}
	new_envp[i_tab] = NULL;
	return (new_envp);
}

char	**ft_remove_var(t_args *args, char *variable)
{
	char	**new_envp;
	char	*env;
	int		i;

	env = ft_getenv(args, variable);
	if (!env)
		return (ft_copy_envp(args->envp));
	free(env);
	i = ft_get_envp_size(args->envp);
	new_envp = malloc(sizeof(char *) * (i + 1));
	if (!new_envp)
		return (NULL);
	new_envp = ft_remove_env_var(args, new_envp, variable);
	return (new_envp);
}
