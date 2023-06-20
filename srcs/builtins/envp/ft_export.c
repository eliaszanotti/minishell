/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:01:43 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/06/20 13:19:42 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_print_export(t_args *args)
{
	t_envp	*envp;

	envp = args->envp;
	while (envp)
	{
		if (!envp->equal)
			printf("declare -x %s\n", envp->name);
		else
			printf("declare -x %s=\"%s\"\n", envp->name, envp->value);
		envp = envp->next;
	}
}

static void	ft_free_name_value(char *name, char *value)
{
	free(name);
	free(value);
}

int	ft_export(t_args *args, char **cmd)
{
	char	*var_name;
	char	*var_value;
	int		i;
	int		add;

	i = 0;
	add = 0;
	if (!cmd[i + 1])
		ft_print_export(args);
	while (cmd[++i])
	{
		var_name = ft_get_var_name(cmd[i], &add);
		if (!var_name)
			return (1);
		var_value = ft_get_var_value(args, cmd[i]);
		if (!var_value)
			return (free(var_name), 1);
		if (*var_name && ft_add_var_to_envp(args, var_name, var_value, add))
			return (1);
		else if (!*var_name)
			ft_free_name_value(var_name, var_value);
	}
	return (0);
}
