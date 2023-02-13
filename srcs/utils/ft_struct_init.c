/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:51:23 by elias             #+#    #+#             */
/*   Updated: 2023/02/13 11:42:09 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_create_list(t_args *args, char **char_envp)
{
	t_envp	*envp;
	t_envp	*new;
	int		i;
	int		j;

	envp = NULL;
	i = -1;
	j = 0;
	while (char_envp[++i])
	{
		j = 0;
		while (char_envp[i][j] && ft_is_variable(char_envp[i][j]))
			j++;
		new = ft_envpnew(ft_substr(char_envp[i], 0, j), \
			ft_substr(char_envp[i], j + 1, ft_strlen(char_envp[i]) - j - 1));
		if (!new)
			return (ft_error(99));
		ft_envpadd_back(&envp, new);
	}
	args->envp = envp;
	return (0);
}

int	ft_struct_init(t_args *args, char **envp)
{
	if (ft_create_list(args, envp))
		return (1);
	args->exit_code = 0;
	args->infile = STDIN_FILENO;
	args->outfile = STDOUT_FILENO;
	args->stack = NULL;
	return (0);
}

int	ft_reset_struct(t_args *args)
{
	char	cwd[PATH_MAX];

	args->prompt = ft_get_prompt(args, getcwd(cwd, sizeof(cwd)));
	args->infile = STDIN_FILENO;
	args->outfile = STDOUT_FILENO;
	args->stack = NULL;
	args->size = 0;
	return (0);
}
