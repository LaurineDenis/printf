# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/13 14:57:14 by ldenis            #+#    #+#              #
#    Updated: 2021/03/03 09:45:35 by ldenis           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

BLUE =\033[0;38;5;123m
LIGHT_PINK = \033[0;38;5;200m
PINK = \033[0;38;5;198m
DARK_BLUE = \033[1;38;5;110m
GREEN = \033[1;32;111m
LIGHT_GREEN = \033[0;38;5;121m
LIGHT_RED = \033[0;31;5;110m
FLASH_GREEN = \033[33;32m
WHITE_BOLD = \033[37m
GREY = \033[3;90m
ORANGE = \033[3;91m
YELLOW = \033[0;33m

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

OBJ_PATH	= obj/

OBJ_NAME	= ${SRCS:.c=.o}

OBJ			= $(addprefix $(OBJ_PATH), $(OBJ_NAME))

HEADER		= libft.h

RM			= rm -rf

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

$(OBJ_PATH)%.o:	%.c $(HEADER)
				@printf "\033[2K\r$(LIGHT_PINK)Compiling:	\033[37m$<\033[36m \033[0m"
				@${CC} ${CFLAGS} -I includes -c $< -o $@

all:			$(OBJ_PATH) ${NAME}
				@:

$(OBJ_PATH):
				@echo "$(BLUE)\n\n\t\tLIBFT :\n"
				@mkdir -p obj/ 2> /dev/null

$(NAME):		${OBJ}
				@ar rcs ${NAME} ${OBJ}

clean:
				@${RM} ${OBJ_PATH}
				@echo ""
				@echo "\t\t$(ORANGE)[Delete objs libft done]"
				@echo ""

fclean:			clean
				@${RM} ${NAME}

re:				fclean all

norme:
					@/usr/bin/norminette $(SRCS_NAME) | grep -v "42 header"
