/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:01:43 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/26 18:37:40 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//TODO export ARG ne doit pas marcher 

/*static char	**ft_remove_env_norm(t_args *args, char *cmd, char **envp)
{
	char	*tmp;
	int		j;
	int		i;

	i = -1;
	j = 0;
	while (args->envp[++i])
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

int	ft_remove_env(char *cmd, t_args *args)
{
	char	**envp_tmp;
	int		i;

	i = 0;
	while (args->envp[i])
		i++;
	envp_tmp = malloc(sizeof(char *) * (i));
	if (!envp_tmp)
		return (ft_error(99));
	args->envp = ft_remove_env_norm(args, cmd, envp_tmp);
	if (!args->envp)
		return (ft_error(99));
	return (0);
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
	while (args->envp[++i])
	{
		envp_tmp[i] = ft_strdup(args->envp[i]);
		if (!envp_tmp[i])
			return (ft_error(99));
	}
	envp_tmp[i] = ft_new_env(cmd[1]);
	envp_tmp[++i] = NULL;
	args->envp = NULL;
	args->envp = envp_tmp;
	return (0);
}

int	ft_already_exist(char **cmd, t_args *args)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = -1;
	while (args->envp[++i])
	{
		tmp = ft_get_var_name(args->envp[i]);
		tmp2 = ft_get_var_name(cmd[1]);
		if (!tmp)
			return (1);
		if (!ft_strcmp(tmp, tmp2))
		{
			free(tmp);
			if (ft_remove_env(tmp2, args))
				return (-1);
			return (ft_add_var(cmd, args));
		}
		free(tmp);
		free(tmp2);
	}
	ft_add_var(cmd, args);
	return (0);
}*/





char	**ft_add_to_envp(char **envp, char *variable)
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
	// TODO free envp
	return (new_envp);
}

void ll(char **env)
{
	while (*env)
	{
		printf(">> %s\n", *env);
		env++;
	}
}

char	*ft_get_new_var(t_args *args, char *name, char *variable)
{
	char	*new_var;
	char	*value;
	int		size;
	
	value = ft_getenv(args, name);
	printf("value = %s\n", value);
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

char	**ft_replace_env2(t_args *args, char *variable) // TODO change name
{
	char	**new_envp;
	char	*new_var;
	int		i;

	i = 0;
	while (variable[i] && variable[i] != '+' && variable[i] != '=')
		i++;
	if (!variable[i])
		return (args->envp);
	new_var = ft_substr(variable, 0, i);
	if (variable[i] == '+' && variable[i + 1] == '=')
		variable = ft_get_new_var(args, new_var, variable);
	printf("var = %s\n", new_var);
	printf("value = %s\n", variable);
	new_envp = ft_get_new_envp(args, new_var); // TODO change to remove ...
	new_envp = ft_add_to_envp(new_envp, variable);
	//free(new_var); 
	return (new_envp);
}

int	ft_export(char **cmd, t_args *args)
{
	char	**new_envp;
	int		i;
	
	i = 0;
	while (cmd[++i])
	{
		new_envp = ft_replace_env2(args, cmd[i]);
		//ft_ll(new_envp);
		args->envp = new_envp;
		if (!args->envp)
			return (ft_error(99));
		// TODO free new_envp
	}
	return (0);
}
