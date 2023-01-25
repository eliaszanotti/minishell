/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:01:43 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/25 17:34:31 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**ft_rm_env_norm(t_args *args, char *cmd, char **envp)
{
	char	*tmp;
	int		j;
	int		i;

	i = -1;
	j = 0;
	while (args->envp[++i] != NULL)
	{
		tmp = ft_get_var_name(args->envp[i]);
		if (!tmp)
			return (NULL);
		if (ft_strcmp(tmp, cmd))
		{
			envp[j] = ft_strdup(args->envp[i]);
			if (!envp[j++])
				return (NULL);
		}
		free(tmp);
	}
	envp[i] = NULL;
	return (envp);
}

int	ft_rm_env(char *cmd, t_args *args)
{
	char	**envp_tmp;
	int		i;

	i = 0;
	while (args->envp[i] != NULL)
		i++;
	envp_tmp = malloc(sizeof(char *) * (i));
	if (!envp_tmp)
		return (1);
	args->envp = ft_rm_env_norm(args, cmd, envp_tmp);
	if (!args->envp)
		return (1);
	return (0);
}

char	*ft_new_env(char *env)
{
	int		i;
	char	*new_env;

	new_env = malloc(sizeof(char) * (ft_strlen(env) + 1));
	i = 0;
	while (*env && *env != '+')
		new_env[i++] = *env++;
	if (*env)
	{
		env++;
		while (*env)
			new_env[i++] = *env++;
	}
	new_env[i] = '\0';
	return (new_env);
}

int	ft_add_var(char **cmd, t_args *args)
{
	char	**envp_tmp;
	int		i;

	i = 0;
	while (args->envp[i] != NULL)
		i++;
	envp_tmp = malloc(sizeof(char *) * (i + 2));
	if (!envp_tmp)
		return (1);
	i = -1;
	while (args->envp[++i] != NULL)
	{
		envp_tmp[i] = ft_strdup(args->envp[i]);
		if (!envp_tmp[i])
			return (1);
	}
	envp_tmp[i] = ft_new_env(cmd[1]);
	envp_tmp[++i] = NULL;
	args->envp = NULL;
	args->envp = envp_tmp;
	return (0);
}

char	*ft_get_value(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[1][i] && cmd[1][i] != '=')
		i++;
	return (cmd[1] + i + 1);
}

int	ft_already_exist(char **cmd, t_args *args)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = -1;
	while (args->envp[++i] != NULL)
	{
		tmp = ft_get_var_name(args->envp[i]);
		tmp2 = ft_get_var_name(cmd[1]);
		if (!tmp)
			return (1);
		if (!ft_strcmp(tmp, tmp2))
		{
			free(tmp);
			if (ft_rm_env(tmp2, args))
				return (-1);
			return (ft_add_var(cmd, args));
		}
		free(tmp);
		free(tmp2);
	}
	ft_add_var(cmd, args);
	return (0);
}

int	ft_export(char **cmd, t_args *args)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	while (cmd[1][i] != '\0' && cmd[1][i] != '=')
		i++;
	if (cmd[1][i - 1] == '+')
	{
		i = -1;
		while (args->envp[++i] != NULL)
		{
			tmp = ft_get_var_name(args->envp[i]);
			tmp2 = ft_get_var_name(cmd[1]);
			if (!tmp)
				return (1);
			if (!ft_strcmp(tmp, tmp2))
			{
				args->envp[i] = ft_strjoin(args->envp[i], ft_get_value(cmd));
				return (0);
			}
			free(tmp);
		}
		return (ft_add_var(cmd, args));
	}
	return (ft_already_exist(cmd, args));
}
