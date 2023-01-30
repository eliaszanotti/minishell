/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:51:23 by elias             #+#    #+#             */
/*   Updated: 2023/01/30 15:27:10 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_struct_init(t_args *args, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	args->envp = malloc(sizeof(char *) * (i + 1));
	if (!args->envp)
		return (ft_error(99));
	i = -1;
	while (envp[++i])
		args->envp[i] = ft_strdup(envp[i]);
	args->envp[i] = NULL;
	args->exit_code = 0;
	args->infile = STDIN_FILENO;
	args->outfile = STDOUT_FILENO;
	return (0);
}

int	ft_reset_struct(t_args *args)
{
	char	cwd[PATH_MAX];

	args->prompt = ft_get_prompt(args, getcwd(cwd, sizeof(cwd)));
	args->infile = STDIN_FILENO;
	args->outfile = STDOUT_FILENO;
	args->size = 0;
	return (0);
}
