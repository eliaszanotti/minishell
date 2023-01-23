/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:48:29 by ezanotti          #+#    #+#             */
/*   Updated: 2023/01/23 20:25:24 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parse_args(t_args *args, char *command)
{
	int	error_code;

	if (ft_split_quote(args, command, ' '))
		return (1);
	if (ft_check_parsing(args))
		return (1);
	if (ft_get_stack(args))
		return (1);
	error_code = ft_parse_quotes(args);
	if (error_code)
		return (error_code);
	if (ft_check_command(args))
		return (1);
	return (0);
}
