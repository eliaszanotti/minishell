/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:15:59 by elias             #+#    #+#             */
/*   Updated: 2022/12/27 17:38:40 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int	ft_prompt_loop(void) // test
{
	char *command;
	int i = 0;
	while (1)
	{
		command = readline("OK>");
		printf("Commande envoyee : %s\n", command);
		if (i == 4)
			break ;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	ft_prompt_loop();

	(void)argc;
	(void)argv;
	return (ft_error(99)); // test
}
