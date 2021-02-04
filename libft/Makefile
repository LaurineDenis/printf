# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/13 14:57:14 by ldenis            #+#    #+#              #
#    Updated: 2021/02/04 11:52:28 by ldenis           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRCS		= ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c \
 ft_strmapi.c ft_itoa.c ft_split.c ft_strtrim.c ft_strjoin.c ft_substr.c \
 ft_bzero.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memchr.c ft_memcpy.c \
 ft_memset.c ft_strdup.c ft_strlcpy.c ft_strncmp.c ft_strrchr.c ft_toupper.c \
 ft_atoi.c ft_calloc.c ft_isalpha.c ft_isdigit.c ft_memccpy.c ft_memcmp.c \
 ft_memmove.c ft_strchr.c ft_strlcat.c ft_strlen.c ft_strnstr.c ft_tolower.c \
 ft_strcat.c ft_strncpy.c ft_strichr.c ft_putnbr_unsi.c ft_lstmap.c ft_lstiter.c \
 ft_lstclear.c ft_lstdelone.c ft_lstadd_back.c ft_lstlast.c ft_lstsize.c \
 ft_lstadd_front.c ft_lstnew.c ft_strncpy.c ft_counterword.c ft_iszero.c \
 ft_convert_base.c ft_convert_base2.c ft_counterword.c ft_fatoi.c ft_itoa_hexa_l.c \
 ft_itoa_hexa_unsi.c ft_itoa_unsi.c ft_iszero.c

OBJS		= ${SRCS:.c=.o}

HEADER		= libft.h

RM			=	rm -f

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

%.o:		%.c libft.h
			@echo "\033[0;32m [OK] \033[0m       \033[0;33m Compiling:\033[0m" $<
			@${CC} ${CFLAGS} -I includes -c $< -o $@

$(NAME):	all

all:		${OBJS}
			@ar rcs ${NAME} ${OBJS}

clean:
			@${RM}  ${OBJS}
			@echo ""
			@echo "                    \033[0;32m [Delete done] \033[0m"
			@echo ""

fclean:		clean
			@${RM} ${NAME}

re:			fclean all
