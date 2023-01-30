/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:01:43 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/30 18:34:26 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**ft_add_to_envp(char **envp, char *variable)
{
	char	**new_envp;
	int		i;

	i = ft_get_envp_size(envp);
	new_envp = malloc(sizeof(char *) * (i + 2));
	if (!new_envp)
		return (NULL);
	i = -1;
	while (envp[++i])
		new_envp[i] = ft_strdup(envp[i]);
	new_envp[i++] = variable;
	new_envp[i] = NULL;
	return (new_envp);
}

static char	*ft_get_new_var(t_args *args, char *name, char *variable)
{
	char	*new_var;
	char	*value;
	int		size;

	value = ft_getenv(args, name);
	while (*variable != '=')
		variable++;
	variable++;
	size = ft_strlen(name) + ft_strlen(variable) + 1;
	if (value)
		size += ft_strlen(value);
	new_var = malloc(sizeof(char) * (size + 1));
	new_var[0] = '\0';
	strcat(new_var, name);
	strcat(new_var, "=");
	if (value)
		strcat(new_var, value);
	return (strcat(new_var, variable));
}

static char	**ft_get_new_envp(t_args *args, char *variable) //TODO
{
	char	**new_envp;
	char	*new_var;
	int		i;

	i = 0;
	while (variable[i] && variable[i] != '+' && variable[i] != '=')
		i++;
	if (!variable[i])
		return (ft_copy_envp(args->envp));
	new_var = ft_substr(variable, 0, i);
	if (variable[i] == '+' && variable[i + 1] == '=')
		variable = ft_get_new_var(args, new_var, variable);
	new_envp = ft_remove_var(args, new_var);
	new_envp = ft_add_to_envp(new_envp, variable);
	free(new_var); 
	return (new_envp);
}

int	ft_export(char **cmd, t_args *args)
{
	char	**new_envp;
	int		i;

	i = 0;
	while (cmd[++i])
	{
		new_envp = ft_get_new_envp(args, cmd[i]);
		if (!new_envp)
			return (ft_error(99));
		//if (changed)
		ft_free_str(args->envp);
		//if (!changed)
		//	args->envp = ft_copy_envp(new_envp);
		//else 
		args->envp = new_envp;
			
		//ft_free_str(new_envp);
		//new_envp = NULL;
	}
	return (0);
}
