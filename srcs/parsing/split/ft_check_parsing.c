/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:24:09 by elias             #+#    #+#             */
/*   Updated: 2023/06/14 13:51:16 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_parsing(t_args *args)
{
	t_list	*command_list;

	command_list = args->command_list;
	if (!command_list)
		return (1);
	if (ft_is_delimiter(command_list) == '|')
		return (ft_error(21, NULL));
	while (command_list)
	{
		if (ft_is_delimiter(command_list) && !command_list->next)
			return (ft_error(23, NULL));
		if (ft_is_delimiter(command_list) == '|' && command_list->next)
			if (ft_is_delimiter(command_list->next) == '|')
				return (ft_error(21, NULL));
		if (ft_is_redirect(command_list) && command_list->next)
			if (ft_is_delimiter(command_list->next))
				return (ft_error(22, NULL));
		command_list = command_list->next;
	}
	return (0);
}
