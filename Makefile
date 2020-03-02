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


LIB = libft
FLAGS = -Wall -Wextra -Werror
OBJECTS = $(SRC:.c=.o)


all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	gcc -o $(NAME) $(OBJECTS) -L /Users/niimu/Documents/code/MinilibX -lmlx -framework OpenGL -framework AppKit

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

cleandup:
	@find . -type f -name '*~' -exec rm -rf {} \;

norme:
	@norminette $(SRC)%