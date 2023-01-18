# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 14:08:57 by elias             #+#    #+#              #
#    Updated: 2023/01/18 12:33:29 by elias            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SOURCES
S_MNSH	= ${DIR_SRC}main.c				\
		${DIR_SRC}ft_error.c 			\
		${DIR_SRC}ft_env.c 				\
		${DIR_SRC}ft_exec_builtins.c	\
		${DIR_SRC}ft_free.c 			\
		${DIR_SRC}ft_get_prompt.c		\
		${DIR_SRC}ft_get_path.c 		\
		${D_PARSE}ft_parse_quotes.c 	\
		${D_PARSE}ft_parsing.c 			\
		${D_PARSE}ft_split_quote.c	 	\
		${D_PARSE}ft_get_stack.c	 	\
		${D_PARSE}ft_get_instructions.c	\
		${D_PARSE}ft_add_to_stack.c		\
		${DIR_SRC}ft_struct_init.c 		\
		${DIR_SRC}ft_utils.c 			\

OBJS	= ${S_MNSH:.c=.o}

# DIRECTORIES
DIR_SRC = srcs/
D_PARSE	= ${DIR_SRC}parsing/

# LIB
LIBFT 	= -L ./libft -lft 

# VARIABLES
NAME	= minishell
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3
RM		= rm -rf

# COMPILATION
all :		${NAME}

%.o: %.c	${DIR_SRC}minishell.h Makefile
			@echo -ne "${YELLOW}${SUPPR}Creating minishell's objects : $@"
			@${CC} ${CFLAGS} -I ./libft -I ${DIR_SRC} -c $< -o ${<:.c=.o} 

${NAME}:	ascii lib ${OBJS}
			@echo -ne "${GREEN}${SUPPR}Creating minishell's objects : DONE\n"
			@echo -ne "${YELLOW}Compiling ${NAME}...${DEFAULT}"
			@${CC} ${OBJS} -o ${NAME} ${LIBFT} -lreadline
			@echo -e "${GREEN}${SUPPR}Compiling ${NAME} : DONE ${DEFAULT}\n"

lib :
			@make -C ./libft

ascii :
			@echo -e "$$ASCII"

clean :		ascii
			@echo -e "${RED}Deleting objects : DONE"
			@${RM} ${OBJS}

fclean :	clean 
			@echo -e "${RED}Cleaning libft : DONE"
			@${MAKE} fclean -C ./libft
			@echo -e "${RED}Deleting executable : DONE${DEFAULT}\n"
			@${RM} ${NAME} 

re :		fclean all

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
DEFAULT = \033[0m
SUPPR = \r\033[2K
MAKEFLAGS += --no-print-directory

define ASCII

███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗
████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     
██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     
██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     
██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗
╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝

endef
export ASCII

.PHONY : all re clean fclean lib ascii
