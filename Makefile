#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thalme <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/27 14:46:32 by thalme            #+#    #+#              #
#    Updated: 2020/02/27 14:46:33 by thalme           ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = fdf

SRC = \
		main.c \
		bresenham.c\
		bresenham2.c\
		key_bindings.c\
		read_map.c\
		manipulate_map.c


LIB = libft
FLAGS = -Wall -Wextra -Werror
OBJECTS = $(SRC:.c=.o)


all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLAGS) -c $(SRC)
	gcc -o $(NAME) $(OBJECTS) libft/libft.a -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

cleandup:
	@find . -type f -name '*~' -exec rm -rf {} \;

norme:
	@norminette $(SRC)