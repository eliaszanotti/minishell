/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:43:07 by elias             #+#    #+#             */
/*   Updated: 2023/05/02 15:53:43 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sig_ignore(int sig)
{
	(void)sig;
	rl_on_new_line();
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_redisplay();
	g_last_errno = 130;
}

void	ft_sign(int sig)
{
	(void)sig;
	rl_on_new_line();
	write(1, "\n", 1);
	rl_replace_line("", 0);
	g_last_errno = 130;
}

void	ft_quit(int sig)
{
	(void)sig;
	write(1, "Quit : 3\n", 10);
	g_last_errno = 131;
}
