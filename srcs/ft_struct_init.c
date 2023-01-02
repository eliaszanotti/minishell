/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:51:23 by elias             #+#    #+#             */
/*   Updated: 2023/01/02 17:52:57 by event02          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_struct_init(t_args *args)
{
	args->prompt = "\e[36;1mminishell\e[32m ➜\e[0m ";
	args->exit_code = 0;
	return (0);
}
