/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:01:43 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/31 16:45:49 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*static char	**ft_add_to_envp(char **envp, char *variable)
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

char	**ft_get_new_envp(t_args *args, char *variable) //TODO
{
	char	**new_envp;
	char	**tmp;
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
	tmp = ft_remove_var(args, new_var);
	free(new_var); 
	new_envp = ft_add_to_envp(tmp, variable);
	ft_free_str(tmp);
	return (new_envp);
}*/

char	*ft_get_new_value3(char *value1, char *value2, int add)
{
	char	*new_value;
	
	if (add)
		new_value = ft_strjoin(value1, value2);
	else
		new_value = ft_strdup(value2);
	free(value1);
	free(value2);
	return (new_value);
}

int	ft_add_variable(t_args *args, char *name, char *value, int add)
{
	t_envp	*envp;
	t_envp	*new;

	envp = args->envp2;
	while (envp && ft_strcmp(name, envp->name))
		envp = envp->next;
	if (!envp)
	{
		new = ft_envpnew(name, value);
		if (!new)
			return (ft_error(99));
		ft_envpadd_back(&args->envp2, new);
		return (0);
	}
	value = ft_get_new_value3(envp->value, value, add);
	printf("value = %s\n", value);
	envp->value = value;
	return (0);
}

char	*ft_get_var_name2(char *var, int *add)
{
	int	i;

	i = 0;
	while (var[i] && ft_is_variable(var[i]))
		i++;
	if (var[i] == '+' && var[i + 1] == '=')
	{
		*add = 1;
		return (ft_substr(var, 0, i));
	}
	if (var[i] == '=')
		return (ft_substr(var, 0, i));
	return (NULL);
}

char	*ft_get_var_value2(char *var)
{
	int	i;

	i = 0;
	while (var[i] && ft_is_variable(var[i]))
		i++;
	if (var[i] == '+' && var[i + 1] == '=')
		return (ft_substr(var, i + 2, ft_strlen(var) - i - 1));
	if (var[i] == '=')
		return (ft_substr(var, i + 1, ft_strlen(var) - i));
	return (NULL);
}

char	*ft_get_new_var2(t_args *args, char *var_name, char *var_value)
{
	t_envp	*envp;
	char	*tmp;

	envp = args->envp2;
	tmp = ft_substr(var_name, 0, ft_strlen(var_name) - 1);
	while (envp && ft_strcmp(tmp, envp->name))
		envp = envp->next;
	return (ft_strjoin(envp->value, var_value));
}

int	ft_export(char **cmd, t_args *args)
{
	char	*var_name;
	char	*var_value;
	int		i;
	int		add;

	i = 0;
	add = 0;
	while (cmd[++i])
	{
		var_name = ft_get_var_name2(cmd[i], &add);
		var_value = ft_get_var_value2(cmd[i]);
		if (!var_name || !var_value)
			return (1);
		printf("name || %s, value || %s\n", var_name, var_value);
		printf("add = %d\n", add);
		if (ft_add_variable(args, var_name, var_value, add))
			return (1);
	}
	return (0);
}
