# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgalli <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 15:32:41 by sgalli            #+#    #+#              #
#    Updated: 2023/03/13 11:51:57 by sgalli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER		= libft.h

NAME		= libft.a

SOURCES		:= ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putnbr_fd.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strjoin.c \
		ft_itoa.c \
		ft_striteri.c \
		ft_strmapi.c \
		ft_strtrim.c \
		ft_putendl_fd.c \
		ft_substr.c\
		str_digit.c

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
