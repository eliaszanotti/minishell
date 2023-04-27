/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:11:11 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/04/27 17:17:03 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_is_valid_num(char *command)
{
	int	i;

	i = -1;
	while (command[++i])
	{
		if (!ft_isalpha(command[i]))
			return (1);
	}
	return (0);
}

int	ft_exit(t_args *args, char **command)
{
	args->exit_code = 1;
	if (command[1])
	{
		if (ft_is_valid_num(command[1]))
		{
			printf("exit\n");
			errno = ft_atoi(command[1]) % 256;
		}
		else
		{
			printf("exit\n");
			errno = 2;
			return (ft_error(21));
		}
		if (command[2])
		{
			args->exit_code = 0;
			return (ft_error(22));
		}
	}
	else
		printf("exit\n");
	return (0);
}
