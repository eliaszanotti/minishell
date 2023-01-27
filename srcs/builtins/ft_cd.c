/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:00:59 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/27 20:32:39 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(char **cmd) // FIX
{
	if (cmd[1])
	{
		if (!ft_strcmp(cmd[1], "~"))
		{
			if (chdir(getenv("HOME")) == -1)
				return (ft_error(20));
		}
		else if (chdir(cmd[1]) == -1)
			return (ft_error(20));
	}
	else if (chdir(getenv("HOME")) == -1)
		return (ft_error(20));
	return (0); // TODO fix
}
