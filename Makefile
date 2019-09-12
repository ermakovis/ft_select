# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcase <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 11:31:10 by tcase             #+#    #+#              #
#    Updated: 2019/08/11 09:39:46 by tcase            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_select

CC=gcc
FLAGS= -Wall -Werror -Wextra

SRC_DIR=./src
OBJ_DIR=./obj
LIB_DIR=./libft

SRC_NAME=main.c\
		init.c\
		init_select.c\
		move.c\
		choose.c\
		clear.c\
		print.c\
		select_funcs.c\
		cleanup.c

SRC = $(addprefix $(OBJ_DIR)/, $(SRC_NAME:.c=.o))
INC = -I ./includes -I $(LIB_DIR)/includes

all: $(NAME)

$(NAME) : $(SRC)
	@make -s -C $(LIB_DIR)
	@$(CC) -o $(NAME) $(SRC) $(LIB_DIR)/libft.a $(INC) -lcurses

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p obj
	@$(CC) -o $@ -c $< $(INC) 
	@echo "\033[0m\033[36m$(notdir $<)\033[1m\033[34m OK\033[0m"

clean:
		@make clean -s -C $(LIB_DIR)
		@rm -f $(SRC)

fclean: clean
		@make fclean -s -C $(LIB_DIR)
		@find . -type f -name ".*.swp" -exec rm -f {} \;
		@rm -rf *test*
		@rm -rf $(NAME)*

re:	fclean all

.PHONY: all, clean, fclean, re
