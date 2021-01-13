# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laurinedenis <laurinedenis@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/13 14:57:14 by ldenis            #+#    #+#              #
#    Updated: 2021/01/13 16:11:15 by laurinedeni      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRC_PATH	= ./src/

SRCS		= $(addprefix ${SRC_PATH},\
			printf.c flags.c fonctions.c \
			utils.c verif.c aff.c linked_list.c \
			print_x_bigx.c grid_fonction.c parsing.c)

OBJS		= ${SRCS:.c=.o}

HEADER		= ft_printf.h

RM			=	rm -f

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

LIB			= libft/libft.a

%.o:		%.c ft_printf.h
			@echo "\033[0;32m [OK] \033[0m       \033[0;33m Compiling:\033[0m" $<
			@${CC} ${CFLAGS} -c $< -o $@

all:		${NAME}

$(NAME):	${OBJS} ft_libft
			@ar rcs ${NAME} ${OBJS} ${LIB}

ft_libft:
			@make -C libft

clean:
			@${RM} ${OBJS}
			@make clean -C libft

fclean:		
			@${RM} ${OBJS}
			@${RM} ${NAME}
			@make -C libft fclean

re:			fclean all
