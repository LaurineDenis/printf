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

SRCS		= printf.c

OBJS		= ${SRCS:.c=.o}

HEADER		= printf.h

RM			=	rm -f

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

%.o:		%.c printf.h
			${CC} ${CFLAGS} -I includes -c $< -o $@

all:		${NAME}

$(NAME):	${OBJS}
			ar rcs ${NAME} ${OBJS}

clean:
			${RM}  ${OBJS} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
