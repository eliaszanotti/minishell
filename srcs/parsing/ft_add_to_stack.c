/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:29:17 by elias             #+#    #+#             */
/*   Updated: 2023/01/17 17:25:09 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_add_redirects(t_args *args, char **command_list, int i_stack, int max)
{
	while (--max > 0 && *command_list)
	{
		if (ft_is_delimiter(*command_list) && command_list[1])
		{
			args->stack[i_stack++] = ft_copy_stack(command_list++, 2);
			max--;
		}
		command_list++;
	}
	return (i_stack);
}

char	**ft_init_instruction(char **command_list, int max)
{
	char	**instruction;
	int		i;

	i = -1;
	while (++i < max - 1 && command_list[i])
		if (ft_is_delimiter(command_list[i]) && command_list[i + 1])
			i++;
	instruction = malloc(sizeof(char *) * (i + 1));
	if (!instruction)
		return (NULL);
	return (instruction);
}

int	ft_add_command(t_args *args, char **command_list, int i_stack, int max)
{
	char	**instruction;
	int		i_tab;

	instruction = ft_init_instruction(command_list, max);
	if (!instruction)
		return (-1);
	i_tab = 0;
	while (--max > 0 && *command_list)
	{
		if (ft_is_delimiter(*command_list) && command_list[1])
		{
			command_list += 2;
			max--;
		}
		else
			instruction[i_tab++] = *command_list++;
	}
	instruction[i_tab] = NULL;
	if (i_tab)
		args->stack[i_stack++] = instruction;
	return (i_stack);
}
