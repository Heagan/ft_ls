
NAME = app

SRC = ft_ls.c\
		sort_list.c\

LIB = -L ./libft -lft

all:
	gcc -o $(NAME) $(SRC) $(LIB)
	@echo "Dont forget to change the name to ft_ls"

