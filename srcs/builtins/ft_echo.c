/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:59:43 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/05/10 18:51:31 by elias            ###   ########.fr       */
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

static int	ft_print_loop(t_args *args, char **cmd, int n, int first)
{
	int	i;

	i = 0;
	while (cmd[++i])
	{
		if (first)
		{
			if (ft_is_flag(cmd[i]) && i == 1)
				n = 1;
			else
			{
				ft_printf_fd("%s", args->outfile, cmd[i]);
				first = 0;
			}
		}
		else
			ft_printf_fd(" %s", args->outfile, cmd[i]);
	}
	return (n);
}

int	ft_echo(t_args *args, char **cmd)
{
	int	first;
	int	n;

	first = 1;
	n = 0;
	n = ft_print_loop(args, cmd, n, first);
	if (!n)
		ft_printf_fd("\n", args->outfile);
	if (!args->last)
		exit(0);
	return (1);
}
