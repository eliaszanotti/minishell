/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:21:53 by elias             #+#    #+#             */
/*   Updated: 2023/01/23 19:41:40 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_stack_size(char **command_list, int i, int j)
{
	int	count;

	count = 0;
	while (*command_list)
	{
		if (ft_is_delimiter(*command_list) == '|')
		{
			command_list++;
			count++;
		}
		while (*command_list && ft_is_delimiter(*command_list) != '|')
		{
			i++;
			if (ft_is_delimiter(*command_list))
			{
				j++;
				command_list++;
				count++;
			}
			command_list++;
		}
		if (j != i)
			count++;
	}
	return (count);
}

int	ft_init_stack(t_args *args)
{
	int	size;

	size = ft_get_stack_size(args->command_list, 0, 0);
	args->stack = malloc(sizeof(char **) * (size + 1));
	if (!args->stack)
		return (ft_error(99));
	args->stack[size] = NULL;
	return (0);
}

char	**ft_copy_stack(char **command_list, int j)
{
	char	**instruction;
	int		i_tab;
	int		i;

	instruction = malloc(sizeof(char *) * (j + 1));
	if (!instruction)
		return (NULL);
	i_tab = 0;
	i = 0;
	while (command_list[i] && i < j)
		instruction[i_tab++] = command_list[i++];
	instruction[i_tab] = NULL;
	return (instruction);
}

int	ft_get_stack(t_args *args)
{
	int	j;
	int	i_stack;

	if (ft_init_stack(args))
		return (1);
	i_stack = 0;
	while (*args->command_list)
	{
		j = 0;
		if (ft_is_delimiter(*args->command_list) == '|')
		{
			args->stack[i_stack] = ft_copy_stack(args->command_list++, 1);
			if (!args->stack[i_stack++])
				return (ft_error(99));
		}
		while (args->command_list[j] && \
			ft_is_delimiter(args->command_list[j]) != '|')
			j++;
		i_stack = ft_add_redirects(args, args->command_list, i_stack, j + 1);
		i_stack = ft_add_command(args, args->command_list, i_stack, j + 1);
		args->command_list += j;
	}
	args->stack[i_stack] = NULL;
	return (0);
}
