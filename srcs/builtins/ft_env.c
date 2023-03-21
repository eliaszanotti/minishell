/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:20:04 by elias             #+#    #+#             */
/*   Updated: 2023/03/21 17:24:51 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_args *args)
{
	t_envp	*envp;

	envp = args->envp;
	while (envp)
	{
		if (envp->equal)
			printf("%s=%s\n", envp->name, envp->value);
		envp = envp->next;
	}
	return (0);
}
