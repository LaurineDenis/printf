# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/13 14:57:14 by ldenis            #+#    #+#              #
#    Updated: 2020/12/13 14:58:20 by ldenis           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		= printf.a

SRCS		= printf.c flags.c fonctions.c tableau_fonction.c utils.c 

OBJS		= ${SRCS:.c=.o}

HEADER		= printf.h

RM			=	rm -f

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

LIB			= lib/libft.a

%.o:		%.c printf.h
			@echo "\033[0;32m [OK] \033[0m       \033[0;33m Compiling:\033[0m" $<
			@${CC} ${CFLAGS} -I includes -c $< -o $@

all:		${NAME}

$(NAME):	${OBJS} libft
			@ar rcs ${NAME} ${OBJS} lib/*.o

libft:
			@make -C lib

clean:
			@${RM} ${OBJS}
			@make clean -C lib

fclean:		
			@${RM} ${OBJS}
			@${RM} ${NAME}
			@make -C lib fclean

re:			fclean all
