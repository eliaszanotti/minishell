/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:48:29 by ezanotti          #+#    #+#             */
/*   Updated: 2023/06/07 12:41:54 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parse_args(t_args *args, char *command)
{
	if (ft_split_quote(args, command))
		return (1);
	if (ft_remove_null(args))
		return (ft_free_instruction(args->command_list), 1);
	if (ft_check_parsing(args))
		return (ft_free_instruction(args->command_list), 1);
	if (ft_get_stack(args))
		return (ft_free_instruction(args->command_list), 1);
	if (ft_parse_quotes(args))
	{
		ft_free_instruction(args->command_list);
		ft_free_stack(args->stack);
		return (1);
	}
	return (0);
}
