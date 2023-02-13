/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:48:29 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/13 17:15:16 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parse_args(t_args *args, char *command)
{
	if (ft_split_quote(args, command, ' '))
		return (1);
	if (ft_check_parsing(args))
		return (ft_free_instruction(args->cl), 1);
	if (ft_get_stack(args, 0))
		return (ft_free_instruction(args->cl), 1);
	if (ft_parse_quotes(args))
	{
		ft_free_instruction(args->cl);
		ft_free_stack(args->stack);
		return (1);
	}
	if (ft_check_command(args))
	{
		ft_free_instruction(args->cl);
		ft_free_stack(args->stack);
		return (1);
	}
	return (0);
}
