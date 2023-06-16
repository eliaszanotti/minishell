/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:56:29 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/06/16 14:38:41 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

typedef struct s_envp	t_envp;

//	CHAIN
void	ft_envpadd_back(t_envp **lst, t_envp *new);
t_envp	*ft_envplast(t_envp *envp);
t_envp	*ft_envpnew(char *name, char *value, int equal);
int		ft_envpsize(t_envp *envp);

//	ERRORS
int		ft_error(int error_code, char *command);
int		ft_print_error(char *str);

//	FREE
void	ft_free_envp(t_args *args);
void	ft_free_instruction(t_list *instruction);
void	ft_free_stack(t_list *stack);
void	ft_free_str(char **str);

//	LIST
t_list	*ft_lstcopy(t_list *new, int j);
t_list	*ft_lstincrement(t_list *instruction, int i);

//	SIGNALS
void	ft_quit(int sig);
void	ft_sig_ignore(int sig);

//	STRUCT
int		ft_struct_init(t_args *args, char **envp);
int		ft_struct_reset(t_args *args);

//	TYPE
char	*ft_is_builtins(t_list *instruction);
char	*ft_is_char_builtins(char *cmd);
char	ft_is_delimiter(t_list *instruction);
char	ft_is_redirect(t_list *instruction);

int		ft_add_first_vars(t_args *args);
int		ft_check_stat(char *path);
char	**ft_get_char_envp(t_args *args);
char	*ft_get_path(t_args *args, char *cmd);
char	*ft_get_prompt(t_args *args, char *cwd);
char	*ft_getenv(t_args *args, char *name);

#endif
