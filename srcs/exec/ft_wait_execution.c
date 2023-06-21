/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:29:00 by elias             #+#    #+#             */
/*   Updated: 2023/06/21 09:28:42 by tgiraudo         ###   ########.fr       */
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
		if (WIFEXITED(ret) && i == args->size - 1)
			g_last_errno = WEXITSTATUS(ret);
		else if (WIFSIGNALED(ret))
			ft_signals(WTERMSIG(ret));
		if (i >= 1)
			close(args->close_tab[i]);
		i--;
	}
	return (free(args->pid_tab), free(args->close_tab), 0);
}
