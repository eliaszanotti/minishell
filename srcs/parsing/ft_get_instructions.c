/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:37:53 by elias             #+#    #+#             */
/*   Updated: 2023/01/13 18:38:08 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_size(t_args *args)
{
	int	size;
	int	i;

	size = 0;
	i = -1;
	while (args->stack[++i])
		if (ft_get_path(args->stack[i][0]))	
			size++;
	return (size);
}

int	ft_get_instructions(t_args *args)
{
	int	size;
	int	i;
	int	i_array;

	size = ft_get_size(args);
	args->instructions = malloc(sizeof(char **) * (size + 1));
	if (!args->instructions)
		return (99);
	i = -1;
	i_array = 0;
	while (args->stack[++i])
	 	if (ft_get_path(args->stack[i][0]))
			args->instructions[i_array++] = args->stack[i];
	args->instructions[i_array] = NULL;
	return (0);
}
