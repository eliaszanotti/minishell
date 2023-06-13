/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_envp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:07:48 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 14:49:53 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_envp(t_args *args)
{
	t_envp	*envp;
	t_envp	*tmp;

	envp = args->envp;
	while (envp)
	{
		free(envp->name);
		free(envp->value);
		tmp = envp->next;
		free(envp);
		envp = tmp;
	}
}
