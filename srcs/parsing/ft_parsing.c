/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:48:29 by ezanotti          #+#    #+#             */
/*   Updated: 2023/01/27 13:24:15 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_args2(t_args *args)
{
	int i;

	i = 0;
	while (args->command_list[i])
		free(args->command_list[i++]);
	free(args->command_list);
}	

int	ft_parse_args(t_args *args, char *command)
{
	if (ft_split_quote(args, command, ' '))
		return (1);
	if (ft_check_parsing(args))
		return (1);
	if (ft_get_stack(args))
		return (1);
	if (ft_parse_quotes(args))
		return (1);
	if (ft_check_command(args))
		return (1);
	printf("args = %s\n", args->command_list[0]);
	//free(args->command_list);
	//ft_free_args2(args);
	return (0);
}
