# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 14:08:57 by elias             #+#    #+#              #
#    Updated: 2023/01/17 12:29:54 by tgiraudo         ###   ########.fr        #
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
		${DIR_SRC}ft_struct_init.c 		\
		${DIR_SRC}ft_utils.c 			\

OBJS	= ${S_MNSH:.c=.o}

# DIRECTORIES
DIR_SRC = srcs/
D_PARSE	= ${DIR_SRC}parsing/

# LIB
LIBFT 		= -L ./libft -lft 

# VARIABLES
NAME	= minishell
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3
RM		= rm -rf

# COMPILATION
all :		${NAME}

%.o: %.c	${DIR_SRC}minishell.h Makefile
			@printf "${YELLOW}\033[2KCreating minishell's objects : $@\r"
			@${CC} ${CFLAGS} -I ./libft -I ${DIR_SRC} -c $< -o ${<:.c=.o} 
			@printf "${GREEN}\033[2KCreating minishell's objects : DONE\r"

${NAME}:	lib ${OBJS}
			@printf "\n\n${YELLOW}Compiling ${NAME}...${DEFAULT}"
			@${CC} ${OBJS} -o ${NAME} ${LIBFT} -lreadline
			@printf "\r${GREEN}Compiling ${NAME} : DONE ${DEFAULT}\n"

lib :
			@make -C ./libft

clean :
			@echo "${RED}Deleting objects...\n"
			@${RM} ${OBJS}

fclean :	clean
			@echo "${RED}Cleaning libft...\n"
			@${MAKE} fclean -C ./libft
			@echo "${RED}Deleting executable...\n${DEFAULT}"
			@${RM} ${NAME} 

re :		fclean all

.PHONY : all re clean fclean

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m


#TODO add makefile in libft (voir sujet regles communes para 8) 
