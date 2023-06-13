/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_reset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:17:17 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 15:27:11 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_struct_reset(t_args *args)
{
	char	cwd[PATH_MAX];

	args->prompt = ft_get_prompt(args, getcwd(cwd, sizeof(cwd)));
	args->infile = STDIN_FILENO;
	args->outfile = STDOUT_FILENO;
	args->stack = NULL;
	args->size = 0;
	args->fdd = 0;
	args->last = 1;
	args->heredoc_stop = 0;
	return (0);
}
