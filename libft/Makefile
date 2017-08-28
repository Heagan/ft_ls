# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsferopo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/20 12:06:34 by gsferopo          #+#    #+#              #
#    Updated: 2017/08/21 13:23:45 by gsferopo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC1	=	ft_hex.c		\
			ft_realloc.c	\
			get_next_line.c	\
			ft_abs.c		\
			ft_clamp.c		\
			ft_wrap.c		\
			ft_tolowerstr.c	\
			ft_issdigit.c	\
			ft_strnsplit.c	\
			ft_printf.c

SRC2	=	ft_lstnew.c		\
			ft_lstdelone.c	\
			ft_lstdel.c		\
			ft_lstadd.c		\
			ft_lstmap.c		\
			ft_lstiter.c

SRC3	=	ft_memset.c		\
			ft_bzero.c		\
			ft_memcpy.c		\
			ft_memccpy.c	\
			ft_memmove.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_strlen.c		\
			ft_strcpy.c		\
			ft_strdup.c		\
			ft_strcat.c		\
			ft_strncpy.c	\
			ft_strncat.c	\
			ft_strlcat.c	\
			ft_strchr.c		\
			ft_strrchr.c	\
			ft_strstr.c		\
			ft_strnstr.c	\
			ft_strcmp.c		\
			ft_strncmp.c

SRC4	=	ft_atoi.c		\
			ft_isalpha.c	\
			ft_toupper.c	\
			ft_tolower.c	\
			ft_isdigit.c	\
			ft_isascii.c	\
			ft_isalnum.c	\
			ft_isprint.c	\
			ft_memalloc.c	\
			ft_memdel.c		\
			ft_putchar.c	\
			ft_strnew.c		\
			ft_strdel.c		\
			ft_strclr.c		\
			ft_striter.c	\
			ft_striteri.c	\
			ft_strmap.c

SRC5	=	ft_strmapi.c	\
			ft_strequ.c		\
			ft_strnequ.c	\
			ft_strsub.c		\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_putstr.c		\
			ft_putendl.c	\
			ft_putnbr.c		\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_itoa.c		\
			ft_strsplit.c

SRCS	=	$(SRC1) $(SRC2) $(SRC3) $(SRC4) $(SRC5)

OBJ		=	${SRCS:%.c=%.o}

CFLAGS	= 	-Werror -Wextra -Wall

LIB		=	libft.h gnl.h

NAME	=	libft.a

all: $(NAME) $(SRC) Makefile cp

$(NAME):
	@echo "---COMPILING LIBRARY---"
	@gcc -c $(CFLAGS) $(SRCS) -I.
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "---REMOVING  OBJECTS---"
	@rm -rf $(OBJ)
	@echo "---LIBRARY  COMPLIED---"

clean:
	@echo "---REMOVING  OBJECTS---"
	@rm -rf $(OBJ)

fclean: clean
	@echo "---REMOVING  LIBRARY---"
	@rm -rf $(NAME)

re: fclean all

cp:
	@echo "---COPYING LIBRARY---"
	@cp $(NAME) ../

push:
	@echo "---PUSHING LIBRARY---"
	@$(MAKE) -C ../ push

norm:
	@echo "--------------->NORMING LIBFT<-----------------"
	@norminette $(LIB)
	@echo "-------------->HEADERS ARE DONE<---------------"
	@norminette $(SRC1)
	@echo "--------------->SRCS1 ARE DONE<----------------"
	@norminette $(SRC2)
	@echo "--------------->SRCS2 ARE DONE<----------------"
	@norminette $(SRC3)
	@echo "--------------->SRCS3 ARE DONE<----------------"
	@norminette $(SRC4)
	@echo "--------------->SRCS4 ARE DONE<----------------"
	@norminette $(SRC5)
	@echo "--------------->SRCS5 ARE DONE<----------------"
	@echo "----------------->LIBFT Done:<-----------------"
