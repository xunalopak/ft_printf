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

NAME = libftprintf.a

SRC = ft_printf.c \
        ft_strdup.c\
        ft_str.c \
        ft_treatment_char.c\
        ft_treatment_int\
        ft_treatment_pointer\
        ft_treatment_str\
        ft_treatment_uint\
        ft_treatment_x\


CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRC)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus : all

.PHONY : all clean fclean re bonus