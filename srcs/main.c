/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:15:59 by elias             #+#    #+#             */
/*   Updated: 2022/12/27 17:51:16 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int	ft_prompt_loop(t_args *args) // test
{
	char *command;
	int i = 0;
	while (1)
	{
		command = readline(args->command);
		printf("Commande envoyee : %s\n", command);
		if (i == 5)
			break ;
		i++;
	}
	return (0);
}


int	main(int argc, char **argv)
{
	t_args	*args;
	int		error_code;

	args = malloc(sizeof(t_args));
	if (!args)
		return (ft_error(99));
	error_code = ft_struct_init(args); 
	if (error_code)
		return (ft_error(error_code));

	//printf("%s\n", args->command);
	ft_prompt_loop(args);

	(void)argc;
	(void)argv;
	return (0);
}
