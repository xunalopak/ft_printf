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

SRCS = ft_printf.c \
        ft_strdup.c\
        ft_str.c \
        ft_treatment_char.c\
        ft_treatment_int.c\
        ft_treatment_pointer.c\
        ft_treatment_str.c\
        ft_treatment_uint.c\
        ft_treatment_x.c\
		ft_treatment_xm.c\


CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I ./includes

OBJS	= $(SRCS:.c=.o)

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)

bonus:		all

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all


.PHONY : all clean fclean re bonus