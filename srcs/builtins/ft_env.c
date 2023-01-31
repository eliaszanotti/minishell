/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:20:04 by elias             #+#    #+#             */
/*   Updated: 2023/01/31 14:38:48 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_args *args) // TODO change  name
{
	t_envp	*envp;

	envp = args->envp2;
	while (envp)
	{
		printf("%s=%s\n", envp->name, envp->value);
		envp = envp->next;	
	}
	return (0);

	/*int		i;

	i = -1;
	while (cmd[i])
		i++;
	if (i > 1)
		return (1);
	i = -1;
	while (args->envp[++i])
		printf("%s\n", args->envp[i]);
	return (0);*/
}
