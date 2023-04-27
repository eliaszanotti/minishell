/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:59:43 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/04/27 15:18:48 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_is_flag(char *str)
{
	int	i;

	i = 0;
	if (str[i++] == '-')
	{
		while (str[i] && str[i] == 'n')
			i++;
		if (!str[i])
			return (1);
		return (0);
	}
	return (0);
}

int	ft_echo(t_args *args, char **cmd)
{
	int	first;
	int	n;
	int	i;

	first = 1;
	n = 0;
	i = 0;
	while (cmd[++i])
	{
		if (ft_is_flag(cmd[i]))
			n = 1;
		else if (!first)
			ft_printf_fd(" %s", args->outfile, cmd[i]);
		else
		{
			ft_printf_fd("%s", args->outfile, cmd[i]);
			first = 0;
		}
	}
	if (!n)
		ft_printf_fd("\n", args->outfile);
	if (!args->last)
		exit(0);
	return (1);
}
