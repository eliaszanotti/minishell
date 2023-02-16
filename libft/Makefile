# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 16:29:50 by tgiraudo          #+#    #+#              #
#    Updated: 2023/02/16 15:12:29 by ezanotti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S_LIB		= ${D_CHAR}ft_atoi.c			\
			${D_CHAR}ft_isalnum.c			\
			${D_CHAR}ft_isalpha.c			\
			${D_CHAR}ft_isascii.c			\
			${D_CHAR}ft_isdigit.c			\
			${D_CHAR}ft_isprint.c			\
			${D_CHAR}ft_itoa.c				\
			${D_CHAR}ft_tolower.c			\
			${D_CHAR}ft_toupper.c			\
			${D_ILST}ft_ilstadd_back.c		\
			${D_ILST}ft_ilstadd_front.c		\
			${D_ILST}ft_ilstlast.c			\
			${D_ILST}ft_ilstnew.c			\
			${D_ILST}ft_ilstsize.c			\
			${D_LST}ft_lstadd_back.c		\
			${D_LST}ft_lstadd_front.c		\
			${D_LST}ft_lstclear.c			\
			${D_LST}ft_lstdelone.c			\
			${D_LST}ft_lstiter.c			\
			${D_LST}ft_lstlast.c			\
			${D_LST}ft_lstmap.c				\
			${D_LST}ft_lstnew.c				\
			${D_LST}ft_lstsize.c			\
			${D_MEM}ft_bzero.c				\
			${D_MEM}ft_calloc.c				\
			${D_MEM}ft_memchr.c				\
			${D_MEM}ft_memcmp.c				\
			${D_MEM}ft_memcpy.c				\
			${D_MEM}ft_memmove.c			\
			${D_MEM}ft_memset.c				\
			${D_PUT}ft_putchar_fd.c			\
			${D_PUT}ft_putendl_fd.c			\
			${D_PUT}ft_putnbr_fd.c			\
			${D_PUT}ft_putstr_fd.c			\
			${D_STR}ft_split.c				\
			${D_STR}ft_strcat.c				\
			${D_STR}ft_strchr.c				\
			${D_STR}ft_strcmp.c				\
			${D_STR}ft_strdup.c				\
			${D_STR}ft_striteri.c			\
			${D_STR}ft_strjoin.c			\
			${D_STR}ft_strlcat.c			\
			${D_STR}ft_strlcpy.c			\
			${D_STR}ft_strlen.c				\
			${D_STR}ft_strmapi.c			\
			${D_STR}ft_strncmp.c			\
			${D_STR}ft_strnstr.c			\
			${D_STR}ft_strrchr.c			\
			${D_STR}ft_strtrim.c			\
			${D_STR}ft_substr.c				\

OBJS		= $(patsubst %.c, $(D_OBJS)%.o, $(S_LIB))

# VARIABLES
NAME		= libft.a
CC			= cc

# FLAGS
MAKEFLAGS	+= --no-print-directory
CFLAGS		= -Wall -Wextra -Werror -I . -g3

# COMMANDS
RM			= rm -rf
PRINT		= @printf

# DIRECTORIES
D_OBJS		= .objs/
D_CHAR		= char/
D_ILST		= ilst/
D_LST		= lst/
D_MEM		= mem/
D_PUT		= put/
D_STR		= str/

# COLORS
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
DEFAULT		= \033[0m
SUPPR		= \r\033[2K

all:		${NAME}

${D_OBJS}%.o:%.c	libft.h Makefile
			@mkdir -p $(shell dirname $@)
			@${PRINT} "${YELLOW}${SUPPR}Creating libft's objects : $@"
			@${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			@${PRINT} "${GREEN}${SUPPR}Creating libft's objects : DONE\n"
			@${PRINT} "${YELLOW}Compiling libft... ${DEFAULT}"
			@ar rc ${NAME} ${OBJS}
			@${PRINT} "${GREEN}${SUPPR}Compiling libft : DONE ${DEFAULT}\n"

clean:
			@${RM} ${D_OBJS}

fclean:		clean
			@${RM} ${NAME} 

re:			fclean all

.PHONY:		all re clean fclean
