# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldenis <ldenis@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/13 14:57:14 by ldenis            #+#    #+#              #
#    Updated: 2021/03/03 09:48:35 by ldenis           ###   ########lyon.fr    #
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

NAME			= libftprintf.a

SRCS_PATH		= src/

SRCS_NAME		= ft_printf.c flags.c fonctions.c \
				utils.c verif.c aff.c linked_list.c \
				print_x_bigx.c grid_fonction.c parsing.c \
				free_lst.c

SRCS			=	$(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJ_PATH		=	obj/

OBJ_NAME		= ${SRCS_NAME:.c=.o}

OBJ				=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))

HEADER			= ft_printf.h

RM				=	rm -rf

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra

LIB				= libft/libft.a

$(OBJ_PATH)%.o:		$(SRCS_PATH)%.c ft_printf.h
					@printf "\033[2K\r$(LIGHT_PINK)Compiling:	\033[37m$<\033[36m \033[0m"
					@sleep 0.1
					@${CC} ${CFLAGS} -I includes -c $< -o $@ -g3

all:				$(OBJ_PATH) ${NAME}
					@:

$(OBJ_PATH):
					@echo "$(BLUE)\n\t\tPRINTF :\n"
					@mkdir -p obj/ 2> /dev/null

$(NAME):			${OBJ} library
					@ar rcs ${NAME} ${OBJ} libft/obj/*
					@echo "$(GREEN)\n\n\t\t[OK]\n"

library:
					@make -C libft

clean:
					@${RM} ${OBJ_PATH}
					@echo ""
					@echo "\t\t$(ORANGE)[Delete objs ft_printf done]"
					@echo ""
					@make clean -C libft

fclean:
					@${RM} ${OBJ_PATH}
					@${RM} ${NAME}
					@echo ""
					@echo "\t\t$(ORANGE)[Delete objs ft_printf done]"
					@echo ""
					@make -C libft fclean

re:					fclean all

norme:
					@/usr/bin/norminette $(SRCS_PATH)
