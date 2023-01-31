/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:20:04 by elias             #+#    #+#             */
/*   Updated: 2023/01/31 19:41:54 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_args *args)
{
	t_envp	*envp;

	envp = args->envp;
	while (envp)
	{
		printf("%s=%s\n", envp->name, envp->value);
		envp = envp->next;
	}
	return (0);
}
