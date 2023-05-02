/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:11:11 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/05/02 14:12:12 by thibaultgir      ###   ########.fr       */
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
			last_errno = ft_atoi(command[1]) % 256;
		}
		else
		{
			printf("exit\n");
			last_errno = 2;
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
