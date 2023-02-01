/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pid_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:26:22 by elias             #+#    #+#             */
/*   Updated: 2023/02/01 11:51:50 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_wait_execution(t_args *args)
{
	int	i;

	i = args->size - 1;
	while (i >= 0)
	{
		waitpid(args->pid_tab[i--], NULL, 0);
		//close(STDOUT_FILENO);
		//close(STDIN_FILENO);
	}
	return (0);
}

int	ft_add_pid(t_args *args, pid_t pid)
{
	int	i;

	i = 0;
	while (args->pid_tab[i] != 0 && i < args->size)
		i++;
	if (i < args->size)
		args->pid_tab[i] = pid;
	return (0);
}
