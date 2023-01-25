/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:00:59 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/24 16:01:19 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_open_dir(char **cmd)
{
	if (cmd[1])
	{
		if (!ft_strcmp(cmd[1], "~"))
		{
			if (chdir(getenv("HOME")) == -1)
				printf("cd: permission denied: %s\n", cmd[1]);
		}
		else if (chdir(cmd[1]))
			printf("cd: permission denied: %s\n", cmd[1]);
	}
	else if (chdir(getenv("HOME")) == -1)
		printf("cd: permission denied: %s\n", cmd[1]);
	return (1);
}
