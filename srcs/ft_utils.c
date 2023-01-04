/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:43:07 by elias             #+#    #+#             */
/*   Updated: 2023/01/04 14:09:09 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_delimiter(char *str)
{
	if (!ft_strcmp(str, "|") || !ft_strcmp(str, "<") || !ft_strcmp(str, ">"))
		return (1);
	if (!ft_strcmp(str, "<<") || !ft_strcmp(str, ">>"))
		return (1);
	return (0);
}

void	ft_count_delimiter(char *cmd, t_args *args)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (cmd[i])
	{
		if (cmd[i] == '|')
			count++;
		if (cmd[i] == '>' || cmd[i] == '<')
		{
			if (cmd[i + 1] == cmd[i])
			{
				i++;
			}
			count++;
		}
		i++;
	}
	args->delimiter = malloc(sizeof(char *) * (count + 1));
	args->delimiter[count + 1] = NULL;
}

void	ft_get_delimiter(char *cmd, t_args *args)
{
	int index;
	int j;
	
	index = 0;
	ft_count_delimiter(cmd, args);
	while(*cmd)
	{
		j = 0;
		if(*cmd == '|')
			j++;
		if(*cmd == '>' || *cmd == '<')
		{
			if (*(cmd + 1) == *cmd)
				j++;
			j++;
		}
		if (j != 0)
		{
			args->delimiter[index] = malloc(sizeof(char) * (j + 1));
			args->delimiter[index++] = ft_substr(cmd, 0, j);
			printf("[%s]\n", args->delimiter[index - 1]);
		}
		if (j == 2)
			cmd++;
		cmd++;
	}
}