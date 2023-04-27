/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:20:04 by elias             #+#    #+#             */
/*   Updated: 2023/04/27 15:20:52 by elias            ###   ########.fr       */
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
			ft_printf_fd("%s=%s\n", args->outfile, envp->name, envp->value);
		envp = envp->next;
	}
	return (0);
}
