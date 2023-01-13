/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:48:29 by ezanotti          #+#    #+#             */
/*   Updated: 2023/01/13 18:39:26 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parse_args(t_args *args, char *command)
{
	int	error_code;

	error_code = ft_split_quote(args, command, ' ');
	if (error_code)
		return (error_code);
	error_code = ft_get_stack(args);
	if (error_code)
		return (error_code);
	error_code = ft_parse_quotes(args);
	if (error_code)
		return (error_code);
	error_code = ft_get_instructions(args);
	if (error_code)
		return (error_code);
	return (0);
}
