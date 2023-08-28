# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/30 11:48:36 by sangwoki          #+#    #+#              #
#    Updated: 2023/08/28 13:22:18 by sangwoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = gcc -Wextra -Werror -Wall -Lmlx -lmlx -framework OpenGL -framework \
Appkit $(SRCS) -o $(NAME)
NAME = miniRT
LIBFT = ./libft/libft.a
SRCS = 	

OBJS = $(SRCS:.c=.o)
INCS = ./interface.h \
		./parsing/parsing.h \
		./signal/signal.h \
		./execute/execute.h

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