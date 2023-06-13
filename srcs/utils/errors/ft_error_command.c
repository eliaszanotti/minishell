/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:15:31 by elias             #+#    #+#             */
/*   Updated: 2023/06/13 15:26:33 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_error_command(char *command)
{
	ft_printf_fd("\e[1;31m[ERROR]\e[0m ", STDERR_FILENO);
	ft_printf_fd("%s : Command not found\n", STDERR_FILENO, command);
	return (0);
}
