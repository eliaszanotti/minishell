/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:56:29 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/03/21 18:49:43 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

//	ft_error.c
int		ft_error_command(char *command);
int		ft_error(int error_code);
//	ft_free.c
void	ft_free_str(char **str);
void	ft_free_instruction(t_list *instruction);
void	ft_free_stack(t_list *stack);
void	ft_free_envp(t_args *args);
//	ft_get_path.c
char	*ft_get_path(t_args *args, char *cmd);
//	ft_get_prompt.c
char	*ft_get_prompt(t_args *args, char *cwd);
//	ft_is_type.c
char	*ft_is_char_builtins(char *cmd);
char	*ft_is_builtins(t_list *instruction);
char	ft_is_delimiter(t_list *instruction);
char	ft_is_redirect(t_list *instruction);
int		ft_is_command(t_args *args, t_list *instruction);
//	ft_list_utils.c
t_list	*ft_lstincrement(t_list *instruction, int i);
t_list	*ft_lstcopy(t_list *new, int j);
//	ft_struct_init.c
int		ft_struct_init(t_args *args, char **envp);
int		ft_reset_struct(t_args *args);
//	ft_utils.c
void	ft_sig_ignore(int sig);
void	ft_sign(int sig);
void	ft_free_args(t_args *args);

char	**ft_get_char_envp(t_args *args);
char	*ft_getenv(t_args *args, char *name);

#endif
