/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:51:23 by elias             #+#    #+#             */
/*   Updated: 2023/01/31 12:14:18 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_envp	*ft_envpnew(char *name, char *value)
{
	t_envp	*envp;

	envp = malloc(sizeof(t_envp));
	if (!envp)
		return (NULL);
	envp->name = name;
	envp->value = value;
	envp->next = NULL;
	return (envp);
}

t_envp	*ft_envplast(t_envp *envp)
{
	while (envp)
	{
		if (!envp->next)
			return (envp);
		envp = envp->next;
	}
	return (envp);
}

void	ft_envpadd_back(t_envp **lst, t_envp *new)
{
	t_envp	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_envplast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}

int	ft_is_variable(char c)
{
	char	*var;

	var = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789?_";
	while (*var)
		if (c == *var++)
			return (1);
	return (0);	
}

int	ft_create_list(t_args *args, char **char_envp)
{
	t_envp	*envp;
	t_envp	*new;
	int i;
	int	j;

	envp = NULL;
	i = -1;
	j = 0;
	while (char_envp[++i])
	{
		j = 0;
		while (char_envp[i][j] && ft_is_variable(char_envp[i][j]))
			j++;;
		new = ft_envpnew(ft_substr(char_envp[i], 0, j), \
			ft_substr(char_envp[i], j + 1, ft_strlen(char_envp[i]) - j - 1));
		if (!new)
			return (ft_error(99));
		ft_envpadd_back(&envp, new);
	}
	args->envp2 = envp;
	return (0);
}

int	ft_struct_init(t_args *args, char **envp)
{
	if (ft_create_list(args, envp))
		return (1);
	t_envp *first = args->envp2;
	while (first)
	{
		printf("%s:%s\n", first->name, first->value);
		first = first->next;	
	}

	args->envp = ft_copy_envp(envp);
	args->exit_code = 0;
	args->infile = STDIN_FILENO;
	args->outfile = STDOUT_FILENO;
	printf("ok\n\n");
	return (0);
}

int	ft_reset_struct(t_args *args)
{
	char	cwd[PATH_MAX];

	args->prompt = ft_get_prompt(args, getcwd(cwd, sizeof(cwd)));
	args->infile = STDIN_FILENO;
	args->outfile = STDOUT_FILENO;
	args->size = 0;
	return (0);
}
