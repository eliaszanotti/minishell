# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 14:08:57 by elias             #+#    #+#              #
#    Updated: 2023/06/22 11:06:41 by tgiraudo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS			= $(shell uname -s)

ifeq ($(OS), Linux)
	PRINT	= @printf
endif
ifeq ($(OS), Darwin)
	PRINT	= @printf
endif

S_MNSH_LIST	= main.c									\
			${D_BUILTINS}${D_ENVP}ft_add_var_to_envp.c	\
			${D_BUILTINS}${D_ENVP}ft_export.c			\
			${D_BUILTINS}${D_ENVP}ft_get_value.c		\
			${D_BUILTINS}${D_ENVP}ft_get_var_name.c		\
			${D_BUILTINS}${D_ENVP}ft_get_var_value.c	\
			${D_BUILTINS}${D_ENVP}ft_is_variable.c		\
			${D_BUILTINS}${D_ENVP}ft_unset.c			\
			\
			${D_BUILTINS}ft_cd.c						\
			${D_BUILTINS}ft_echo.c						\
			${D_BUILTINS}ft_env.c						\
			${D_BUILTINS}ft_exec_builtins.c				\
			${D_BUILTINS}ft_exit.c						\
			${D_BUILTINS}ft_pwd.c						\
			\
			${D_EXEC}ft_add_pid.c						\
			${D_EXEC}ft_child_execution.c				\
			${D_EXEC}ft_exec.c							\
			${D_EXEC}ft_exit_and_free.c					\
			${D_EXEC}ft_heredoc.c						\
			${D_EXEC}ft_redirect.c						\
			${D_EXEC}ft_wait_execution.c				\
			\
			${D_PARSE}${D_ILST}ft_add_errno_to_ilst.c	\
			${D_PARSE}${D_ILST}ft_add_var_to_ilst.c		\
			${D_PARSE}${D_ILST}ft_ilst_to_char.c		\
			\
			${D_PARSE}${D_QUOTES}ft_add_char.c			\
			${D_PARSE}${D_QUOTES}ft_add_double.c		\
			${D_PARSE}${D_QUOTES}ft_add_single.c		\
			${D_PARSE}${D_QUOTES}ft_add_tilde.c			\
			${D_PARSE}${D_QUOTES}ft_add_variable.c 		\
			${D_PARSE}${D_QUOTES}ft_parse_quotes.c 		\
			\
			${D_PARSE}${D_SPLIT}ft_add_single_str.c		\
			${D_PARSE}${D_SPLIT}ft_check_parsing.c		\
			${D_PARSE}${D_SPLIT}ft_remove_null.c		\
			${D_PARSE}${D_SPLIT}ft_skip_alpha.c			\
			${D_PARSE}${D_SPLIT}ft_skip_expand.c		\
			${D_PARSE}${D_SPLIT}ft_skip_pipe.c			\
			${D_PARSE}${D_SPLIT}ft_skip_redirect.c		\
			${D_PARSE}${D_SPLIT}ft_skip_spaces.c		\
			${D_PARSE}${D_SPLIT}ft_split_quote.c		\
			\
			${D_PARSE}${D_STACK}ft_add_command.c		\
			${D_PARSE}${D_STACK}ft_add_redirects.c		\
			${D_PARSE}${D_STACK}ft_get_stack.c			\
			\
			${D_PARSE}ft_parsing.c 						\
			\
			${D_UTILS}${D_CHAIN}ft_envpadd_back.c		\
			${D_UTILS}${D_CHAIN}ft_envplast.c			\
			${D_UTILS}${D_CHAIN}ft_envpnew.c			\
			${D_UTILS}${D_CHAIN}ft_envpsize.c			\
			\
			${D_UTILS}${D_ERRORS}ft_error.c				\
			${D_UTILS}${D_ERRORS}ft_print_error.c		\
			\
			${D_UTILS}${D_FREE}ft_free_envp.c			\
			${D_UTILS}${D_FREE}ft_free_instruction.c	\
			${D_UTILS}${D_FREE}ft_free_stack.c			\
			${D_UTILS}${D_FREE}ft_free_str.c			\
			\
			${D_UTILS}${D_LIST}ft_lstcopy.c				\
			${D_UTILS}${D_LIST}ft_lstincrement.c		\
			\
			${D_UTILS}${D_SIGNALS}ft_signals.c			\
			${D_UTILS}${D_SIGNALS}ft_sig_ignore.c		\
			\
			${D_UTILS}${D_STRUCT}ft_struct_init.c		\
			${D_UTILS}${D_STRUCT}ft_struct_reset.c		\
			\
			${D_UTILS}${D_TYPE}ft_is_builtins.c			\
			${D_UTILS}${D_TYPE}ft_is_char_builtins.c	\
			${D_UTILS}${D_TYPE}ft_is_delimiter.c		\
			${D_UTILS}${D_TYPE}ft_is_redirect.c			\
			\
			${D_UTILS}ft_add_first_vars.c				\
			${D_UTILS}ft_check_stat.c					\
			${D_UTILS}ft_get_prompt.c					\
			${D_UTILS}ft_get_path.c 					\
			${D_UTILS}ft_getenv.c 						\
			${D_UTILS}ft_get_char_envp.c 				\

HDRS_LIST =	minishell.h	\
			exec.h		\
			builtins.h	\
			parsing.h	\
			utils.h		\

OBJS		= $(patsubst %.c, $(DIR_OBJS)%.o, $(S_MNSH))
S_MNSH		= ${addprefix ${DIR_SRC}, ${S_MNSH_LIST}}
HDRS		= ${addprefix ${DIR_INCLUDE}, ${HDRS_LIST}}

# DIRECTORIES
DIR_OBJS	= .objs/
DIR_INCLUDE = includes/
DIR_SRC		= srcs/
D_BUILTINS	= builtins/
D_ENVP		= envp/
D_EXEC		= exec/
D_PARSE		= parsing/
D_ILST		= ilst/
D_QUOTES	= quotes/
D_SPLIT		= split/
D_STACK		= stack/
D_UTILS		= utils/
D_CHAIN		= chain/
D_ERRORS	= errors/
D_FREE		= free/
D_LIST		= list/
D_SIGNALS	= signals/
D_STRUCT	= struct/
D_TYPE		= type/

# LIB
LIBFT		= -L ./libft -lft 

# VARIABLES
NAME		= minishell
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
RM			= rm -rf
MAKEFLAGS	+= --no-print-directory

# COLORS
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
CYAN		= \033[1;36m
DEFAULT		= \033[0m
SUPPR		= \r\033[2K

# COMPILATION
all :		ascii \
			lib \
			${NAME}
			

${DIR_OBJS}%.o: %.c	${HDRS} Makefile
			@mkdir -p $(shell dirname $@)
			@${PRINT} "${YELLOW}${SUPPR}Creating ${NAME}'s objects : $@"
			@${CC} ${CFLAGS} -I ./libft -I ${DIR_INCLUDE} -c $< -o $@ 

${NAME}:	${OBJS} 
			@make lib
			@${PRINT} "${GREEN}${SUPPR}Creating ${NAME}'s objects : DONE\n"
			@${PRINT} "${YELLOW}Compiling ${NAME}...${DEFAULT}"
			@${CC} ${OBJS} -o ${NAME} ${LIBFT} -lreadline
			@${PRINT} "${GREEN}${SUPPR}Compiling ${NAME} : DONE ${DEFAULT}\n"

lib:
			@make -C ./libft

clean:	
			@${PRINT} "${RED}Deleting objects : DONE\n"
			@${RM} ${DIR_OBJS}

fclean:		clean 
			@${PRINT} "${RED}Cleaning libft : DONE\n"
			@${MAKE} fclean -C ./libft
			@${PRINT} "${RED}Deleting executable : DONE${DEFAULT}\n"
			@${RM} ${NAME} 

re:			fclean all

ascii:
			@${PRINT} "$$ASCII\n"

define ASCII
${CYAN}
███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗
████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     
██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     
██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     
██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗
╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝
${DEFAULT}
endef
export ASCII

.PHONY :	all re clean fclean lib ascii
