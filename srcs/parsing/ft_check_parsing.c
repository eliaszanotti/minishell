/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:24:09 by elias             #+#    #+#             */
/*   Updated: 2023/01/27 17:03:32 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_parsing(t_args *args)
{
	int	i;

	i = -1;
	if (!*args->command_list)
		return (1);
	if (ft_is_delimiter(*args->command_list) == '|')
		return (ft_error(4));
	while (args->command_list[++i])
	{
		if (ft_is_delimiter(args->command_list[i]) && \
			!args->command_list[i + 1])
			return (ft_error(6));
		if (ft_is_delimiter(args->command_list[i]) == '|' && \
			args->command_list[i + 1])
			if (ft_is_delimiter(args->command_list[i + 1]) == '|')
				return (ft_error(4));
		if (ft_is_redirect(args->command_list[i]) && \
			args->command_list[i + 1])
			if (ft_is_delimiter(args->command_list[i + 1]))
				return (ft_error(5));
	}
	return (0);
}

int	ft_check_command(t_args *args)
{
	int		i;

	i = -1;
	while (args->stack[++i])
		if (!ft_is_delimiter(args->stack[i][0]) && \
			!ft_is_command(args->stack[i][0]) && \
			!ft_is_builtins(args->stack[i][0]))
			return (ft_error(2));
	return (0);
}
