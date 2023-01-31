/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:03:48 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/31 12:27:04 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	ft_unset(char **cmd, t_args *args)
{
	int		i;
	t_envp	*envp;
	t_envp	*backup;

	i = 0;
	envp = args->envp2;
	while (cmd[++i])
	{
		printf("cmd = %s\n", cmd[i]);
		while (envp)
		{
			printf("%s, %s\n", envp->name, backup->name);
			if (!ft_strcmp(envp->name, cmd[i]))
			{
				backup->next = envp->next;
				printf("\t\t%s\n", envp->name);
				break;
			}
			backup = envp;
			envp = envp->next;
		}


		//new_envp = ft_remove_var(args, cmd[i]);
		//ft_free_str(args->envp);
		//ft_free_str(new_envp);
		//if (!new_envp)
		//	return (ft_error(99));
		//ft_free_str(args->envp);
		//args->envp = new_envp;
		//ft_free_str(new_envp);
		// TODO free new_envp
	}
	t_envp *first = args->envp2;
	while (first)
	{
		printf("%s:%s\n", first->name, first->value);
		first = first->next;
	}

	//ll(args->envp);
	return (0);
}
