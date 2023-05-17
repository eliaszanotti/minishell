/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:59:43 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/05/17 13:33:20 by elias            ###   ########.fr       */
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

static int	ft_print_loop(t_args *args, char **cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
	{
		if (i == 0)
			ft_printf_fd("%s", args->outfile, cmd[i]);
		else
			ft_printf_fd(" %s", args->outfile, cmd[i]);
	}
	return (0);
}

int	ft_echo(t_args *args, char **cmd)
{
	int	n;

	n = 0;
	while (ft_is_flag(*++cmd))
		n = 1;
	if (ft_print_loop(args, cmd))
		return (1);
	if (!n)
		ft_printf_fd("\n", args->outfile);
	if (!args->last)
		exit(0);
	return (1);
}
