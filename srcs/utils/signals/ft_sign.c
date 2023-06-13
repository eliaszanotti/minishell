/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sign.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:11:52 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 15:26:20 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sign(int sig)
{
	(void)sig;
	rl_on_new_line();
	write(1, "\n", 1);
	rl_replace_line("", 0);
	g_last_errno = 130;
}