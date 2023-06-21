/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:11:11 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/06/21 10:21:28 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_is_valid_num(char *command)
{
	int						i;
	unsigned long long int	res;

	i = -1;
	res = 0;
	while (command[++i])
	{
		if (!ft_isdigit(command[i]))
		{
			if (command[i] != '-' && command[i] != '+' && i != 0)
				return (0);
			else
				i++;
		}
		res = (res * 10) + command[i] - '0';
		if (res > 9223372036854775807)
			return (0);
	}
	return (1);
}

int	ft_exit(t_args *args, char **command)
{
	args->exit_code = 1;
	if (command[1])
	{
		if (ft_is_valid_num(command[1]))
		{
			printf("exit\n");
			g_last_errno = ft_atoi(command[1]) % 256;
		}
		else
		{
			printf("exit\n");
			g_last_errno = 2;
			return (ft_error(24, NULL));
		}
		if (command[2])
		{
			args->exit_code = 0;
			g_last_errno = 1;
			return (ft_error(13, NULL));
		}
	}
	else
		printf("exit\n");
	return (0);
}
