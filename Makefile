# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgalli <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 11:06:24 by sgalli            #+#    #+#              #
#    Updated: 2023/03/13 12:29:00 by sgalli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT	=	client
SERVER	=	server


LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft


FT_PRINTF	=	./ft_printf/libftprintf.a
FT_PRINTF_DIR	=	./ft_printf

SOURCE_CLIENT	=	client.c
SOURCE_SERVER	=	server.c
INCLUDE		=	-I. -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)


CC		=	gcc
GCCFLAG		= -fsanitize=leak -g -Wall -Wextra -Werror
REMOVE		=	rm -f


GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]



all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER): $(LIBFT) $(FT_PRINTF)
	@ $(CC) $(D_FLAG) $(GCCFLAG) $(SOURCE_SERVER) $(LIBFT) $(FT_PRINTF) $(INCLUDE) -o $(SERVER)
	@printf "\t$(_SUCCESS) server ready\n\n"


$(CLIENT): $(LIBFT) $(FT_PRINTF)
	@ $(CC) $(D_FLAG) $(GCCFLAG) $(SOURCE_CLIENT) $(LIBFT) $(FT_PRINTF) $(INCLUDE) -o $(CLIENT)
	@printf "\t$(_SUCCESS) client ready\n\n"


$(LIBFT):
	@ $(MAKE) -s -C ./libft


$(FT_PRINTF):
	@ $(MAKE) -s -C ./ft_printf


clean:
	@ $(MAKE) clean -s -C $(LIBFT_DIR)
	@ $(MAKE) clean -s -C $(FT_PRINTF_DIR)
	@printf "\t$(_INFO) removed all libft object\n\n"
	@printf "\t$(_INFO) removed all ft_printf object\n\n"


fclean:
	@ $(MAKE) fclean -s -C $(LIBFT_DIR)
	@ $(MAKE) fclean -s -C $(FT_PRINTF_DIR)
	@ $(RM) *.o
	@ $(RM) $(CLIENT) $(SERVER)
	@printf "\t$(_INFO) client esecutible removed\n\n"
	@printf "\t$(_INFO) server esecutible removed\n\n"

re: fclean all

mandatory:	$(CLIENT) $(SERVER)
bonus:		mandatory

m : mandatory
b : bonus

.PHONY: all clean fclean re mandatory m bonus b
