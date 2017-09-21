# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsferopo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/21 11:43:10 by gsferopo          #+#    #+#              #
#    Updated: 2017/09/05 09:52:20 by gsferopo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = ft_ls.c \
	  sort_list.c \
	  add.c \
	  file.c \
	  get_info.c \
	  get.c \
	  lst.c \
	  read.c

LIB = ./libft/libft.a

INC = -I. -I./libft

FLAGS = -Werror -Wall -Wextra

all:
	make -C ./libft
	gcc -o $(NAME) $(SRC) $(LIB) $(INC) $(FLAGS)

clean: $(NAME)
	make -C ./libft clean
	rm $(NAME)

fclean: clean
	rm $(LIB)

re: fclean all
	make -C ./libft re
