# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbejot <rbejot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/02 11:37:02 by rbejot            #+#    #+#              #
#    Updated: 2016/04/20 17:19:00 by rbejot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBPATH = ./libft/
LIBMXPATH = ./minilibx/

LIBS = -L$(LIBMXPATH) -lmlx -framework OpenGL -framework AppKit -L$(LIBPATH) -lft

SRC = display_fdf.c ft_isneg.c main.c print_fdf.c read_fdf.c key_event.c

OBJ = $(SRC:.c=.o)

CC = gcc -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@make -C $(LIBPATH)
	@make -C $(LIBMXPATH)
	@$(CC) -c $(SRC)
	@$(CC) $(OBJ) $(LIBS) -o $(NAME)
	@echo compiling...

clean:
	@rm -rf $(OBJ)
	@echo deleting...

fclean:
	@rm -f $(NAME)
	@echo deleting...

re: fclean all
