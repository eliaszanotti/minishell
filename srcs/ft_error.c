/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:14:22 by elias             #+#    #+#             */
/*   Updated: 2023/01/24 12:26:37 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_error(int error_code)
{
	if (error_code)
		printf("\e[1;31m[ERROR:%d]\e[0m ", error_code);
	else if (error_code == 1) // TODO  a enlever car reservee pour dire que le message est deja print
		printf("Parse error (quote not closed)\n");
	else if (error_code == 2)
		printf("Command not found\n");
	else if (error_code == 3)
		printf("Can't open file\n");
	else if (error_code == 4)
		printf("Failed to create fork\n");
	else if (error_code == 5)
		printf("Failed to execute command\n");
	else if (error_code == 6)
		printf("Failed to duplicate fd (dup2 error)\n");
	else if (error_code == 7)
		printf("Failed to pipe fd\n");
	else if (error_code == 8)
		printf("Can't create file\n");
	else if (error_code == 9)
		printf("Parse error on pipe\n");
	else if (error_code == 10)
		printf("Syntax error on redirect\n");
	else if (error_code == 11)
		printf("Parse error\n");
	else if (error_code == 99)
		printf("Malloc cannot be created\n");
	return (error_code);
}
