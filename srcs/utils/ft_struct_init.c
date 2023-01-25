/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:51:23 by elias             #+#    #+#             */
/*   Updated: 2023/01/25 22:01:08 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_struct_init(t_args *args)
{
	args->exit_code = 0;
	args->infile = STDIN_FILENO;
	args->outfile = STDOUT_FILENO;
	return (0);
}

int	ft_reset_struct(t_args *args)
{
	args->infile = STDIN_FILENO;
	args->outfile = STDOUT_FILENO;
	return (0);
}
