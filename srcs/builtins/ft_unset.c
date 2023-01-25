/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:03:48 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/25 16:25:41 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_var_name(char	*var)
{
	char	*new_var;
	int		i;

	i = 0;
	while (var[i] && var[i] != '=' && var[i] != '+')
		i++;
	new_var = malloc(sizeof(char) * (i + 1));
	if (!new_var)
		return (NULL);
	i = 0;
	while (var[i] && var[i] != '=' && var[i] != '+')
	{
		new_var[i] = var[i];
		i++;
	}
	new_var[i] = '\0';
	return (new_var);
}

static char	**ft_unset_norm(t_args *args, char **cmd, char **envp)
{
	char	*tmp;
	int		j;
	int		i;

	i = -1;
	j = 0;
	while (args->envp[++i] != NULL)
	{
		tmp = ft_get_var_name(args->envp[i]);
		if (!tmp)
			return (NULL);
		if (ft_strcmp(tmp, cmd[1]))
		{
			envp[j] = ft_strdup(args->envp[i]);
			if (!envp[j++])
				return (NULL);
		}
		free(tmp);
	}
	envp[i] = NULL;
	return (envp);
}

int	ft_unset(char **cmd, t_args *args)
{
	char	**envp_tmp;
	int		i;

	i = 0;
	while (args->envp[i] != NULL)
		i++;
	envp_tmp = malloc(sizeof(char *) * (i));
	if (!envp_tmp)
		return (1);
	args->envp = ft_unset_norm(args, cmd, envp_tmp);
	if (!args->envp)
		return (1);
	return (0);
}
