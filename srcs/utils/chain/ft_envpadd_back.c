/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envpadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:56:18 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 14:56:33 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_envpadd_back(t_envp **lst, t_envp *new)
{
	t_envp	*last;

	if (!lst)
		return ;
	if (*lst)
	{
		last = ft_envplast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}