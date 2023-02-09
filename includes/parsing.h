/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:35:58 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/02/09 13:13:10 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

typedef struct s_args	t_args;

//	ft_add_to_stack.c
int		ft_add_redirects(t_args *args, char **cmd, int max);
int		ft_add_command(t_args *args, char **cmd, int max);
//	ft_check_parsing.c
int		ft_check_parsing(t_args *args);
char	*ft_is_builtins(char *cmd);
int		ft_check_command(t_args *args);
//	ft_get_stack.c
int		ft_init_stack(t_args *args);
t_list	*ft_copy_stack(char **command_list, int j);
int		ft_get_stack(t_args *args, int j);
//	ft_parse_quotes.c
char	*ft_replace_env(t_args *args, char *str);
int		ft_parse_quotes(t_args *args);
//	ft_parsing.c
int		ft_parse_args(t_args *args, char *command);
//	ft_split_quote.c
int		ft_split_quote(t_args *args, char *s, char c);

#endif
