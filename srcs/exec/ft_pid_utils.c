/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pid_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:26:22 by elias             #+#    #+#             */
/*   Updated: 2023/05/24 16:02:55 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_wait_execution(t_args *args)
{
	int	i;
	int	ret;

	i = args->size - 1;
	while (i >= 0)
	{
		ret = 0;
		waitpid(args->pid_tab[i], &ret, 0);
		if (ret % 256 == 0 && g_last_errno != 127 && i == args->size - 1)
			g_last_errno = WEXITSTATUS(ret);
		if (i >= 1)
			close(args->close_tab[i]);
		i--;
	}
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
