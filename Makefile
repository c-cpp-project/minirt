# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/30 11:48:36 by sangwoki          #+#    #+#              #
#    Updated: 2023/08/30 16:07:30 by sangwoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = gcc -Wextra -Werror -Wall -Lmlx -lmlx -framework OpenGL -framework \
Appkit $(SRCS) -o $(NAME)
NAME = miniRT
LIBFT = ./libft/libft.a
SRCS = 	

OBJS = $(SRCS:.c=.o)
INCS = ./color/mlx_color.c \
		./color/mlx_func.C \
		./parsing/__init__.c \
		./parsing/error_handle.c \
		./parsing/extract.c \
		./parsing/extract2.c \
		./parsing/format_check.c \
		./parsing/ft_math,c \
		./parsing/ft_split_group.c \
		./parsing/ft_split.c \
		./parsing/uti


all : $(NAME)
$(NAME) : $(OBJS)
	make -C ./libft all
	$(CC) $(CFLAGS) $(LINKING_FLAGS) $^ $(LIBFT) -o $@
%.o : %.c
	$(CC) $(CFLAGS) $(COMPILE_FLAGS) -c $< -o $@
clean :
	make -C ./libft fclean
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY: all re fclean clean