/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:29:17 by elias             #+#    #+#             */
/*   Updated: 2023/01/19 17:10:42 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_add_redirects(t_args *args, char **cmd, int i_stack, int max)
{
	while (--max > 0 && *cmd)
	{
		if (ft_is_delimiter(*cmd) && cmd[1])
		{
			args->stack[i_stack++] = ft_copy_stack(cmd++, 2);
			max--;
		}
		cmd++;
	}
	return (i_stack);
}

char	**ft_init_instruction(char **cmd, int max)
{
	char	**instruction;
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (count < max - 1 && *cmd)
	{
		if (ft_is_delimiter(*cmd) && cmd[1])
			cmd++;
		else
			i++;
		count++;
		cmd++;
	}
	instruction = malloc(sizeof(char *) * (i + 1));
	if (!instruction)
		return (NULL);
	return (instruction);
}

int	ft_add_command(t_args *args, char **cmd, int i_stack, int max)
{
	char	**instruction;
	int		i_tab;

	instruction = ft_init_instruction(cmd, max);
	if (!instruction)
		return (-1);
	i_tab = 0;
	while (--max > 0 && *cmd)
	{
		if (ft_is_delimiter(*cmd) && cmd[1])
		{
			cmd += 2;
			max--;
		}
		else
			instruction[i_tab++] = *cmd++;
	}
	instruction[i_tab] = NULL;
	if (i_tab)
		args->stack[i_stack++] = instruction;
	return (i_stack);
}
