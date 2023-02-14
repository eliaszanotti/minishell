/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:59:43 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/02/14 17:15:29 by ezanotti         ###   ########.fr       */
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

int	ft_echo(char **cmd)
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
			printf(" %s", cmd[i]);
		else
		{
			printf("%s", cmd[i]);
			first = 0;
		}
	}
	(void)n;
	//if (!n)
	//	printf("\n");
	return (1);
}
