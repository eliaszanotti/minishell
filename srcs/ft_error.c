/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:14:22 by elias             #+#    #+#             */
/*   Updated: 2023/01/24 12:36:58 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_error(int error_code)
{
	if (error_code)
		printf("\e[41;30m[ERROR:%d]\e[49;31m\ue0b0\e[0m ", error_code);
	if (error_code == 1) // TODO  a enlever car reservee pour dire que le message est deja print
		printf("Parse error (quote not closed)\n");
	if (error_code == 2)
		printf("Command not found\n");
	if (error_code == 3)
		printf("Can't open file\n");
	if (error_code == 4)
		printf("Failed to create fork\n");
	if (error_code == 5)
		printf("Failed to execute command\n");
	if (error_code == 6)
		printf("Failed to duplicate fd (dup2 error)\n");
	if (error_code == 7)
		printf("Failed to pipe fd\n");
	if (error_code == 8)
		printf("Can't create file\n");
	if (error_code == 9)
		printf("Parse error on pipe\n");
	if (error_code == 10)
		printf("Syntax error on redirect\n");
	if (error_code == 11)
		printf("Parse error\n");
	if (error_code == 99)
		printf("Malloc cannot be created\n");
	return (error_code);
}
