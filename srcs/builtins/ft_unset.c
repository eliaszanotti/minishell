/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:03:48 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/26 17:02:51 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO unset ne marche pas

char	*ft_get_var_name(char	*var)
{
	char	*new_var;
	int		i;

	i = 0;
	while (var[i] && var[i] != '=' && var[i] != '+')
		i++;
	new_var = malloc(sizeof(char) * (i + 1));
	if (!new_var)
		return (NULL);
	i = 0;
	while (var[i] && var[i] != '=' && var[i] != '+')
	{
		new_var[i] = var[i];
		i++;
	}
	new_var[i] = '\0';
	return (new_var);
}

static int	ft_get_envp_size(t_args *args)
{
	int	size;

	size = 0; 
	while (args->envp[size])
		size++;
	return (size);
}

static char	*ft_getenv(t_args *args, char *variable)
{
	char	*current;
	int		i;
	int		j;
	
	i = -1;
	while (args->envp[++i])
	{
		j = 0;
		while (args->envp[i][j] && args->envp[i][j] != '=')
			j++;
		if (args->envp[i][j] == '=')
			current = ft_substr(args->envp[i], 0, j);
		if (!current)
			return (NULL);
		if (!ft_strcmp(current, variable))
			return (ft_substr(args->envp[i], \
				j + 1, ft_strlen(args->envp[i]) - j - 1));
		free(current);
	}
	return (NULL);
}
	
static char	*ft_get_var_name2(char *variable)
{
	int		i;

	i = 0;
	while (variable[i] && variable[i] != '=')
		i++;
	if (variable[i] == '=')
		return (ft_substr(variable, 0, i));
	return (NULL);
}

void ft_ll(char **env)
{
	while (*env)
	{
		printf(">> %s\n", *env);
		env++;
	}
}

static char	**ft_copy_new_envp(t_args *args, char **new_envp, char *variable)
{
	char	*current;
	int		i;
	int		i_tab;

	i = 0;
	i_tab = 0;
	while (args->envp[i])
	{
		current = ft_get_var_name2(args->envp[i]);
		if (ft_strcmp(current, variable))
			new_envp[i_tab++] = ft_strdup(args->envp[i]);
		i++;
	}
	new_envp[i_tab] = NULL;
	//ft_ll(new_envp);
	return (new_envp);
}

static char	**ft_fill_new_envp(t_args *args, char *variable)
{
	char	**new_envp;
	int		i;

	if (!ft_getenv(args, variable))
		return (args->envp);
	i = ft_get_envp_size(args);
	new_envp = malloc(sizeof(char *) * i);
	if (!new_envp)
		return (NULL);
	new_envp = ft_copy_new_envp(args, new_envp, variable);
	return (new_envp);
}
	
int	ft_unset(char **cmd, t_args *args)
{
	char	**new_envp;
	int		i;
	
	i = 0;
	while (cmd[++i])
	{
		new_envp = ft_fill_new_envp(args, cmd[i]);
		args->envp = new_envp;
		if (!args->envp)
			return (ft_error(99));
		// TODO free new_envp
	}
	return (0);
}
