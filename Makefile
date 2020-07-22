# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsansa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/22 22:11:24 by gsansa            #+#    #+#              #
#    Updated: 2020/07/22 22:11:24 by gsansa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
FLAGS		=	-Wall -Werror -Wextra
SRC_DIR		=	./src
LIBFT_DIR	=	./libft_mod
OBJ_DIR		=	./objs

SRC			=	ft_max.c \
				ft_printf.c \
				ft_printf_dop.c \
				print_formated_str.c \
				list_formats_pcs.c	\
				list_formats_dxu.c \
				ft_itoa_base.c

LIBFT		=	ft_bzero.c \
				ft_calloc.c \
				ft_itoa.c \
				ft_memset.c	\
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_strdup.c \
				ft_strlen.c	\
				ft_substr.c	\
				ft_toupper.c

HEADERS		=	libftprintf.h			$(LIBFT_DIR)/libft.h

OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRC:c=o))		$(addprefix $(OBJ_DIR)/, $(LIBFT:c=o))

.PHONY: all, re, clean, fclean

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc  $@ $?
	@ranlib $@
	@echo "$(NAME) compiled!"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: ./*/%.c $(HEADERS)| $(OBJ_DIR)
	@gcc $(FLAGS) -c $< -o $@

clean:
	@/bin/rm -f $(OBJS)

fclean: clean 
	@/bin/rm -f $(NAME)

re: fclean all
