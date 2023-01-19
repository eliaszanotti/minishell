/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:51:23 by elias             #+#    #+#             */
/*   Updated: 2023/01/19 16:58:05 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_struct_init(t_args *args)
{
	args->prompt = "\e[36;1mminishell\e[32m ➜\e[0m "; // TODO inutile vu ft_get_prompt
	args->exit_code = 0;
	args->infile = 0;
	args->outfile = 1;
	return (0);
}
