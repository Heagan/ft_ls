# **************************************************************************** #
# 
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsferopo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/09 17:28:48 by gsferopo          #+#    #+#              #
#    Updated: 2017/06/28 08:46:10 by gsferopo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Werror -Wextra -Wall

SRC = $(wildcard src/*.c)

OBJ = $(SRC:src/%.c=build/%.o)

INCLUDES = -Iheader

all: $(NAME) cp

.SILENT:

$(NAME):
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	
build/%.o: src/%.c
	@echo "Building $^"
	gcc -c $(CFLAGS) $(INCLUDES) -o $@ $^


clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

cp: 
	cp $(NAME) ../$(NAME)
