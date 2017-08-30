# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsferopo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/21 11:43:10 by gsferopo          #+#    #+#              #
#    Updated: 2017/08/30 09:52:55 by gsferopo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zpp

SRC = ft_ls.c \
	  sort_list.c \
	  ft_strccmp.c \
	  ft_printf.c

LIB = -L ./libft -lft -I. -I./libft

all:
	gcc -o $(NAME) $(SRC) $(LIB)
	@echo "Dont forget to change the name to ft_ls"

