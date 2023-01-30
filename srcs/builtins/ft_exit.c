/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:11:11 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/30 15:35:16 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_args *args) // TODO
{
	printf("exit\n");
	//ft_free_str(args->envp);
	ft_free_stack(args->stack);
	exit(0);
}
