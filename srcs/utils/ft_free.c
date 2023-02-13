/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:07:48 by elias             #+#    #+#             */
/*   Updated: 2023/02/13 14:30:38 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	ft_free_instruction(t_list *instruction)
{
	t_list	*tmp;

	while (instruction)
	{
		free(instruction->content);
		tmp = instruction->next;
		free(instruction);
		instruction = tmp;
	}
}

void	ft_free_stack(t_list *stack)
{
	t_list	*tmp;

	while (stack)
	{
		ft_free_instruction(stack->content);
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

void	ft_free_envp(t_args *args)
{
	t_envp	*envp;
	t_envp	*tmp;

	envp = args->envp;
	while (envp)
	{
		free(envp->name);
		free(envp->value);
		tmp = envp->next;
		free(envp);
		envp = tmp;
	}
}
