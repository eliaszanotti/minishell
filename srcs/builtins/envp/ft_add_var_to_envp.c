/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_var_to_envp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:36:28 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 14:36:43 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_get_new_value(char *value1, char *value2, int add)
{
	char	*new_value;

	if (add)
		new_value = ft_strjoin(value1, value2);
	else
		new_value = ft_strdup(value2);
	free(value2);
	return (new_value);
}

int	ft_add_var_to_envp(t_args *args, char *name, char *value, int add)
{
	t_envp	*envp;
	t_envp	*new;

	envp = args->envp;
	while (envp && ft_strcmp(name, envp->name))
		envp = envp->next;
	if (!envp)
	{	
		new = ft_envpnew(name, value, args->equal);
		if (!new)
			return (ft_error(99));
		ft_envpadd_back(&args->envp, new);
		return (0);
	}
	free(name);
	value = ft_get_new_value(envp->value, value, add);
	if (!value)
		return (ft_error(99));
	free(envp->value);
	envp->value = value;
	envp->equal = args->equal;
	return (0);
}