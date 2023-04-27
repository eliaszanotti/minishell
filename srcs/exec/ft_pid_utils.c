/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pid_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:26:22 by elias             #+#    #+#             */
/*   Updated: 2023/04/27 16:53:40 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_wait_execution(t_args *args)
{
	int	i;
	int	save;

	i = args->size - 1;
	save = errno;
	while (i >= 0)
	{
		waitpid(args->pid_tab[i], NULL, 0);
		if (i >= 1)
			close(args->close_tab[i]);
		i--;
	}
	errno = save;
	return (free(args->pid_tab), free(args->close_tab), 0);
}

int	ft_add_pid(t_args *args, pid_t pid)
{
	int	i;

	i = 0;
	while (args->pid_tab[i] != 0 && i < args->size)
		i++;
	if (i < args->size)
	{
		args->pid_tab[i] = pid;
		args->close_tab[i] = args->fdd;
	}
	return (0);
}
