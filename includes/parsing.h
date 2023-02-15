/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:35:58 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/02/15 16:22:08 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

typedef struct s_args	t_args;

//	ft_add_to_stack.c
int		ft_add_redirects(t_args *args, t_list *instruction, int max);
int		ft_add_command(t_args *args, t_list *cmd, int max);
//	ft_check_parsing.c
int		ft_check_parsing(t_args *args);
int		ft_check_command(t_args *args);
//	ft_get_stack.c
int		ft_get_stack(t_args *args, int j);
//	ft_parse_quotes.c
char	*ft_replace_env(t_args *args, char *str);
int		ft_parse_quotes(t_args *args);
//	ft_parsing.c
int		ft_parse_args(t_args *args, char *command);
//	ft_skip_utils.c
char	*ft_skip_redirect(t_list **splt_pipe, char *str);
char	*ft_skip_alpha(t_list **splt_pipe, char *str);
char	*ft_skip_pipe(t_list **splt_pipe, char *str);
char	*ft_skip_spaces(char *str);
//	ft_split_quote.c
int		ft_split_quote(t_args *args, char *s);

#endif
