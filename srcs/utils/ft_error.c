/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:14:22 by elias             #+#    #+#             */
/*   Updated: 2023/03/21 19:37:30 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_error_command(char *command)
{
	ft_printf_fd("\e[1;31m[ERROR]\e[0m ", STDERR_FILENO);
	ft_printf_fd("%s : Command not found\n", STDERR_FILENO, command);
	return (errno);
}

static int	ft_error_range_1(int error_code)
{
	errno = 2;
	if (error_code == 3)
		printf("Parse error (quote not closed)\n");
	else if (error_code == 4)
		printf("Parse error on pipe\n");
	else if (error_code == 5)
		printf("Syntax error on redirect\n");
	else if (error_code == 6)
		printf("Parse error at end of command\n");
	return (1);
}

static int	ft_error_range_2(int error_code)
{
	if (error_code == 10)
		printf("Failed to create fork\n");
	else if (error_code == 11)
		printf("Failed to pipe fd\n");
	else if (error_code == 12)
		printf("Failed to execute command\n");
	else if (error_code == 13)
		printf("Failed to duplicate fd (dup2 error)\n");
	else if (error_code == 14)
		printf("Can't open file\n");
	else if (error_code == 15)
		printf("Can't create file\n");
	return (1);
}

int	ft_error(int error_code)
{
	if (error_code)
		printf("\e[1;31m[ERROR:%d]\e[0m ", error_code);
	if (error_code < 10)
		return (ft_error_range_1(error_code));
	else if (error_code < 20)
		return (ft_error_range_2(error_code));
	else if (error_code == 20)
		printf("No such file or directory\n");
	else if (error_code == 99)
	{
		printf("Malloc cannot be created\n");
		return (99);
	}
	else
		printf("Undefined\n");
	return (1);
}
