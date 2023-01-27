/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:37:35 by elias             #+#    #+#             */
/*   Updated: 2023/01/27 15:04:54 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char	ft_is_delimiter(char *str)
{
	if (!ft_strcmp(str, "|"))
		return ('|');
	if (!ft_strcmp(str, "<"))
		return ('<');
	if (!ft_strcmp(str, ">"))
		return ('>');
	if (!ft_strcmp(str, "<<"))
		return ('l');
	if (!ft_strcmp(str, ">>"))
		return ('r');
	return (0);
}

char	ft_is_redirect(char *str)
{
	if (ft_is_delimiter(str) && ft_is_delimiter(str) != '|')
		return (ft_is_delimiter(str));
	return (0);
}

int	ft_is_command(char *cmd)
{
	char	*path;

	path = ft_get_path(cmd);
	if (path)
	{
		free(path);
		return (1);
	}
	free(path);
	return (0);
}
