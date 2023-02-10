/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:21:53 by elias             #+#    #+#             */
/*   Updated: 2023/02/10 16:21:17 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdio.h>
void ll(t_args *args)
{
	t_list	*stack;
	t_list	*instruction;
	char	*str;
	stack = args->stack_list;
	while (stack)
	{
		instruction = stack->content;
		while (instruction)
		{
			str = instruction->content;
			printf("[%s]", str);
			instruction = instruction->next;
		}
		printf("\n");
		stack = stack->next;
	}
}

void	ft_log(t_list *list)
{
	char *str;
	while (list)
	{
		str = list->content;
		printf("log = %s\n", str);
		list = list->next;
	}
}

t_list	*ft_copy_stack(char **command_list, int j)
{
	t_list	*instruction;
	t_list	*new;
	int		i;

	instruction = NULL;
	i = 0;
	while (command_list[i] && i < j)
	{
		new = ft_lstnew(command_list[i++]);
		if (!new)
			return (NULL);
		ft_lstadd_back(&instruction, new);
	}
	return (instruction);
}

t_list	*ft_cpy(t_list *new, int j)
{
	t_list	*instruction;
	t_list	*cpy;

	instruction = NULL;
	while (new && j > 0)
	{
		cpy = ft_lstnew(new->content);
		if (!cpy)
			return (NULL);
		ft_lstadd_back(&instruction, cpy);
		new = new->next;
		j--;
	}
	return (instruction);
}

t_list	*ft_increment_list(t_list *instruction, int i)
{
	while (instruction && i-- > 0)
		instruction = instruction->next;
	return (instruction);
}

int	ft_add_r(t_args *args, t_list *instruction, int max)
{
	t_list	*new;

	while (--max > 0 && instruction)
	{
		if (ft_is_d(instruction) && instruction->next)
		{
			new = ft_lstnew(ft_cpy(instruction, 2));
			if (!new)
				return (ft_error(99));
			ft_lstadd_back(&args->stack_list, new);
			instruction = instruction->next;
			max--;
		}
		instruction = instruction->next;
	}
	return (0);
}

int	ft_add_c(t_args *args, t_list *cmd, int max)
{
	t_list	*instruction;
	t_list	*new;

	instruction = NULL;
	while (--max > 0 && cmd)
	{
		if (ft_is_d(cmd) && cmd->next)
		{
			//cmd += 2;
			cmd = ft_increment_list(cmd, 2);
			max--;
		}
		else
		{
			//new = cmd;
			//if (!new)
			//	return (ft_error(99));
			new = ft_cpy(cmd, 1);
			ft_lstadd_back(&instruction, new);
			cmd = cmd->next;
		}
	}
	new = ft_lstnew(instruction);
	if (!new)
		return (ft_error(99));
	ft_lstadd_back(&args->stack_list, new);
	return (0);
}

int	ft_get_stack(t_args *args, int j)
{
	t_list	*cl;
	t_list	*new;

	cl = args->cl;
	args->stack_list = NULL; // TODO move si error nrm

	/*printf("||\n");
	ft_log(cl);
	cl = ft_increment_list(cl , 2);
	printf("||\n");
	ft_log(cl);
	printf("||\n");
	return (0);*/
	while (cl)
	{
		if (ft_is_d(cl) == '|')
		{
			new = ft_lstnew(ft_cpy(cl, 1));
			if (!new)
				return (ft_error(99));
			ft_log(ft_cpy(cl ,1));
			printf("|||||||||||||||||\n");
			//if (!new || !new->content)
			//	return (ft_error(99)); //TODO free si error
			ft_lstadd_back(&args->stack_list, new);
			cl = cl->next;
			/*new = ft_lstnew(ft_copy_stack(command_list++, 1));
			if (!new || !new->content)
				return (ft_error(99)); //TODO free si error
			ft_lstadd_back(&args->stack_list, new);*/
		}
		

		//printf("%p\n", ft_increment_list(cl, j)->next);
		while (ft_increment_list(cl, j) && ft_is_d(ft_increment_list(cl, j)) != '|')
		{
			//tmp = ft_increment_list(cl, j);
			//printf("OKKKDEKEKKFDEKFKE = %s\n",(char *)tmp->content);
			j++;
		}
		if (ft_add_r(args, cl, j + 1))
			return (ft_error(99));
		if (ft_add_c(args, cl, j + 1))
			return (ft_error(99));
		ft_log(cl);
		//command_list += j;
		//cl = cl->next;
		printf("ok\n");
		cl = ft_increment_list(cl, j);
		//ll(args);
		//return (0);
	}
	ll(args);
	return (0);
}
