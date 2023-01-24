/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:24:09 by elias             #+#    #+#             */
/*   Updated: 2023/01/24 12:58:09 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_parsing(t_args *args)
{
	int	i;

	i = -1;
	if (ft_is_delimiter(*args->command_list) == '|')
		return (ft_error(9));
	while (args->command_list[++i])
	{
		if (ft_is_delimiter(args->command_list[i]) && \
			!args->command_list[i + 1])
			return (ft_error(11));
		if (ft_is_delimiter(args->command_list[i]) == '|' && \
			args->command_list[i + 1])
			if (ft_is_delimiter(args->command_list[i + 1]) == '|')
				return (ft_error(9));
		if (ft_is_redirect(args->command_list[i]) && \
			args->command_list[i + 1])
			if (ft_is_delimiter(args->command_list[i + 1]))
				return (ft_error(10));
	}
	return (0);
}

char	*ft_is_builtins(char *cmd)
{
	if (!ft_strcmp(cmd, "echo"))
		return ("echo");
	else if (!ft_strcmp(cmd, "cd"))
		return ("cd");
	else if (!ft_strcmp(cmd, "pwd"))
		return ("pwd");
	else if (!ft_strcmp(cmd, "export"))
		return ("export");
	else if (!ft_strcmp(cmd, "unset"))
		return ("unset");
	else if (!ft_strcmp(cmd, "env"))
		return ("env");
	else if (!ft_strcmp(cmd, "exit"))
		return ("exit");
	return (NULL);
}

int	ft_check_command(t_args *args) // TODO fix for builtins
{
	int	i;

	i = -1;
	while (args->stack[++i])
		if (!ft_is_delimiter(args->stack[i][0]) && \
			!ft_get_path(args->stack[i][0]) && \
			!ft_is_builtins(args->stack[i][0]))
			return (ft_error(2));
	return (0);
}
