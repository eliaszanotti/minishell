/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:01:43 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/24 16:02:05 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_export(char **cmd, t_args *args)
{
	char	**envp_tmp;
	int		i;

	i = 0;
	while (args->envp[i] != NULL)
		i++;
	envp_tmp = malloc(sizeof(char *) * (i + 2));
	if (!envp_tmp)
		return (1);
	i = -1;
	while (args->envp[++i] != NULL)
	{
		envp_tmp[i] = ft_strdup(args->envp[i]);
		if (!envp_tmp[i])
			return (1);
	}
	envp_tmp[i] = cmd[1];
	envp_tmp[++i] = NULL;
	args->envp = NULL;
	args->envp = envp_tmp;
	return (0);
}
