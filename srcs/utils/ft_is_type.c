/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:37:35 by elias             #+#    #+#             */
/*   Updated: 2023/02/13 13:34:21 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_is_char_builtins(char *cmd)
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

char	*ft_is_builtins(t_list *instruction)
{
	char	*cmd;

	cmd = instruction->content;
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

char	ft_is_delimiter(t_list *instruction)
{
	char	*str;

	str = instruction->content;
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

char	ft_is_redirect(t_list *instruction)
{
	if (ft_is_delimiter(instruction) && ft_is_delimiter(instruction) != '|')
		return (ft_is_delimiter(instruction));
	return (0);
}

int	ft_is_command(t_args *args, t_list *instruction)
{
	char	*cmd;
	char	*path;

	cmd = instruction->content;
	path = ft_get_path(args, cmd);
	if (path)
	{
		free(path);
		return (1);
	}
	free(path);
	return (0);
}
