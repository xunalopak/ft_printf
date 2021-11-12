# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 16:06:09 by rchampli          #+#    #+#              #
#    Updated: 2021/11/10 16:06:09 by rchampli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

FLAGS = -Werror -Wall -Wextra -o -I./include

GCC = gcc

$(NAME): $(OBJ)
		$(GCC) $(NAME) $(OBJ)

all: $(NAME)

clean:
        rm -f $(OBJ)

fclean: clean
        rm -f $(NAME)

re:     fclean all

bonus: all

.PHONY: all clean fclean re bonus