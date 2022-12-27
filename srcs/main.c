/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:15:59 by elias             #+#    #+#             */
/*   Updated: 2022/12/27 17:09:54 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int	ft_prompt_loop(void)
{
	char *command;
	while (1)
	{
		command = readline("OK>");
		printf("Commande envoyee : %s\n", command);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	ft_prompt_loop();

	(void)argc;
	(void)argv;
	return (0);
}
