/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:21:53 by elias             #+#    #+#             */
/*   Updated: 2023/01/17 13:37:03 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_stack_size(t_args *args)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (args->command_list[i])
	{
		if (ft_get_path(args->command_list[i]))
		{
			while (args->command_list[i] && \
				!ft_is_delimiter(args->command_list[i]))
				i++;
			count++;
		}
		if (args->command_list[i])
		{
			i++;
			count++;
		}	
	}
	return (count);
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

int	ft_init_stack(t_args *args)
{
	int	size;

	size = ft_get_stack_size(args) + 15;
	args->stack = malloc(sizeof(char **) * (size + 1));
	if (!args->stack)
		return (99);
	args->stack[size] = NULL;
	return (0);
}

void	ll(char ***stack)
{
	int	i = -1;
	int	j = 0;

	printf("\n---\n");
	while (stack[++i])
	{
		j = 0;
		while (stack[i][j])
			printf("[%s]", stack[i][j++]);
		printf("\n");
	}
}

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

int	ft_add_command(t_args *args, char **command_list, int i_stack, int max)
{
	char	**instruction;
	int		i_tab;
	int		i;

	i = -1;
	while (++i < max && command_list[i])
		if (ft_is_delimiter(command_list[i]) && command_list[i + 1])
			i++;
	instruction = malloc(sizeof(char *) * (i + 1));
	if (!instruction)
		return (0);
	i_tab = 0;
	while (--max > 0 && *command_list)
	{
		if (ft_is_delimiter(*command_list) && command_list[1])
		{
			command_list += 2;
			max -= 1;
		}
		else
			instruction[i_tab++] = *command_list++;
	}
	instruction[i_tab] = NULL;
	args->stack[i_stack++] = instruction;
	return (i_stack);
}


int	ft_get_stack(t_args *args)
{
	int	j;
	int	i_stack;

	i_stack = ft_init_stack(args);
	if (i_stack)
		return (i_stack);
	while (*args->command_list)
	{
		j = 0;
		if (ft_is_delimiter(*args->command_list) == '|')
			args->stack[i_stack++] = ft_copy_stack(args->command_list++, 1);
		
		while (args->command_list[j] && \
			ft_is_delimiter(args->command_list[j]) != '|')
			j++;
		i_stack = ft_add_redirects(args, args->command_list, i_stack, j + 1);
		i_stack = ft_add_command(args, args->command_list, i_stack, j + 1);
		args->command_list += j;
	
	}
	ll(args->stack);
	return (0);
}
