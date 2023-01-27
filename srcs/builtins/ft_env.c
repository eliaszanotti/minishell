/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:20:04 by elias             #+#    #+#             */
/*   Updated: 2023/01/27 20:27:10 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(char **cmd, t_args *args) // TODO change  name
{
	int		i;

	i = -1;
	while (cmd[i])
		i++;
	if (i > 1)
		return (1);
	i = -1;
	while (args->envp[++i])
		printf("%s\n", args->envp[i]);
	return (0);
}
