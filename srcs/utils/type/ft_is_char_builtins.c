/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_char_builtins.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:37:35 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 15:26:46 by elias            ###   ########.fr       */
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
