/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:00:59 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/31 19:43:16 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(t_args *args, char **cmd)
{
	char	*env;

	env = ft_getenv(args, "HOME");
	if (cmd[1])
	{
		if (!ft_strcmp(cmd[1], "~"))
		{
			if (chdir(env) == -1)
				return (free(env), ft_error(20));
		}
		else if (chdir(cmd[1]) == -1)
			return (free(env), ft_error(20));
	}
	else if (chdir(env) == -1)
		return (free(env), ft_error(20));
	return (free(env), 0);
}
