/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:35:58 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/06/07 17:34:14 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

typedef struct s_args	t_args;

//	ft_add_to_ilst.c
int		ft_add_var_to_ilst(t_args *args, t_ilst **str, char *name);
char	*ft_add_errno_to_ilst(t_args *args, t_ilst **str, char *content);
//	ft_add_to_stack.c
int		ft_add_redirects(t_args *args, t_list *instruction, int max);
int		ft_add_command(t_args *args, t_list *cmd, int max);
//	ft_add_to_str.c
char	*ft_add_variable(t_args *args, t_ilst **str, char *content);
char	*ft_add_char(t_ilst **str, char *content);
char	*ft_add_single(t_ilst **str, char *content);
char	*ft_add_double(t_args *args, t_ilst **str, char *content);
//	ft_check_parsing.c
int		ft_check_parsing(t_args *args);
//	ft_get_stack.c
int		ft_get_stack(t_args *args);
//	ft_ilst_to_char.c
char	*ft_ilst_to_char(t_ilst *str);
//	ft_parse_quotes.c
char	*ft_add_tilde(t_args *args, t_ilst **str, char *content);
int		ft_parse_quotes(t_args *args);
//	ft_parsing.c
int		ft_parse_args(t_args *args, char *command);
//  ft_remove_null.c
int		ft_remove_null(t_args *args);
//  ft_skip_expand_utils.c
int		ft_add_single_str(t_list **instruction, char *content);
//	ft_skip_utils.c
char	*ft_skip_redirect(t_list **instruction, char *str);
char	*ft_skip_alpha(t_list **instruction, char *str);
char	*ft_skip_expand(t_args *args, t_list **instruction, char *str);
char	*ft_skip_pipe(t_list **instruction, char *str);
char	*ft_skip_spaces(t_list **instruction, char *str);
//	ft_split_quote.c
int		ft_split_quote(t_args *args, char *s);

#endif
