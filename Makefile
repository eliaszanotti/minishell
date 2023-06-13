# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elias <elias@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 14:08:57 by elias             #+#    #+#              #
#    Updated: 2023/06/13 14:30:40 by elias            ###   ########.fr        #
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
			${D_BUILTINS}ft_cd.c						\
			${D_BUILTINS}ft_echo.c						\
			${D_BUILTINS}ft_env.c						\
			${D_BUILTINS}ft_env_utils.c					\
			${D_BUILTINS}ft_exec_builtins.c				\
			${D_BUILTINS}ft_exit.c						\
			${D_BUILTINS}ft_export.c					\
			${D_BUILTINS}ft_export_utils.c				\
			${D_BUILTINS}ft_pwd.c						\
			${D_BUILTINS}ft_unset.c						\
			\
			${D_EXEC}ft_add_pid.c						\
			${D_EXEC}ft_child_execution.c				\
			${D_EXEC}ft_exec.c							\
			${D_EXEC}ft_heredoc.c						\
			${D_EXEC}ft_pid_utils.c						\
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
			${D_PARSE}${D_SPLIT}ft_check_parsing.c		\
			${D_PARSE}${D_SPLIT}ft_remove_null.c		\
			${D_PARSE}${D_SPLIT}ft_skip_alpha.c			\
			${D_PARSE}${D_SPLIT}ft_skip_expand.c		\
			${D_PARSE}${D_SPLIT}ft_skip_expand_utils.c	\
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
			${D_UTILS}ft_add_first_vars.c	\
			${D_UTILS}ft_chained_envp.c		\
			${D_UTILS}ft_error.c			\
			${D_UTILS}ft_free.c 			\
			${D_UTILS}ft_get_prompt.c		\
			${D_UTILS}ft_get_path.c 		\
			${D_UTILS}ft_getenv.c 			\
			${D_UTILS}ft_get_char_envp.c 	\
			${D_UTILS}ft_is_type.c 			\
			${D_UTILS}ft_list_utils.c		\
			${D_UTILS}ft_struct_init.c 		\
			${D_UTILS}ft_signals.c 			\

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
D_EXEC		= exec/
D_PARSE		= parsing/
D_ILST		= ilst/
D_QUOTES	= quotes/
D_SPLIT		= split/
D_STACK		= stack/
D_UTILS		= utils/

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

.PHONY :	all re clean fclean lib
