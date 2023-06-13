/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envplast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:56:40 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 15:25:37 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_envp	*ft_envplast(t_envp *envp)
{
	while (envp)
	{
		if (!envp->next)
			return (envp);
		envp = envp->next;
	}
	return (envp);
}
