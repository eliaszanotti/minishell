/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:59:43 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/25 10:49:36 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char **cmd)
{
	int	i;

	i = 1;
	if (cmd[1] && !ft_strcmp(cmd[1], "-n"))
		while (cmd[++i])
			printf("%s ", cmd[i]);
	else
	{
		while (cmd[i])
			printf("%s ", cmd[i++]);
		printf("\n");
	}
	return (1);
}
