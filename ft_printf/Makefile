# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgalli <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 09:59:30 by sgalli            #+#    #+#              #
#    Updated: 2022/11/10 16:24:43 by sgalli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

HEADER		= libftprintf.h

SOURCES		:= integer_i_d.c \
		character_c.c \
		ft_printf.c \
		hexadecimal_x.c \
		string_s.c \
		unsigned_integer_u.c \
		hexadecimal_p.c \

OBJECTS		= $(SOURCES:.c=.o)

CFLAGS		= -Wall -Werror -Wextra

CC		= gcc

all		: $(NAME)

$(NAME)		: $(OBJECTS)
		ar -rcs $(NAME) $(OBJECTS)

%.o:%.c
		$(CC) -c $(CFLAGS) -I. $< -o $@

clean:
		rm -f *.o

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY :=	fclean re all clean
