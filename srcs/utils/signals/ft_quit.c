/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:11:28 by elias             #+#    #+#             */
/*   Updated: 2023/06/16 14:41:07 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_quit(int sig)
{
	if (sig == SIGINT)
	{
		g_last_errno = 130;
		write(STDERR_FILENO, "\n", 1);
	}
	else if (sig == SIGQUIT)
	{
		g_last_errno = 131;
		write(STDERR_FILENO, "Quit (core dumped)\n", 19);
	}
}
