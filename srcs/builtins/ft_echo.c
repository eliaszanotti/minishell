/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:59:43 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/26 15:11:54 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char **cmd) // FIX 
{
	int	i;

	i = 1;
	if (cmd[i] && !ft_strcmp(cmd[i], "-n"))
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
