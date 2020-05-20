# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/20 14:41:46 by ccharmai          #+#    #+#              #
#    Updated: 2020/05/20 14:54:07 by ccharmai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP_DIR = ./push_swap/

PS_NAME = push_swap
C_NAME = checker

RED = "\033[1;31m"
GREEN = "\033[1;32m"
RESET = "\033[0;0m"
CYAN = "\033[1;35m"

CC = gcc
FLAGS = -Wall -Werror -Wextra

CHECKER_DIR = ./checker/
CHECKER_HEADER = $(CHECKER_DIR)includes/
C_SRC = ch_main.c \
	ch_order.c \
	check_s.c \
	com_inspect.c \
	ft_atoi.c \
	ft_itoa.c \
	ft_strlen.c \
	ft_strsplit.c \
	ft_strsub.c \
	get_next_line.c \
	new_line.c \
	push_func.c \
	pushtostack.c \
	read_seq.c \
	rever_rotat_func.c \
	rotate_func.c \
	swap_func.c
C_FILES = $(addprefix $(CHECKER_DIR), $(C_SRC))
C_OBJ = $(addprefix $(CHECKER_DIR), $(patsubst %.c, %.o, $(C_SRC)))

OBJ = $(C_OBJ)

.PHONY: all clean fclean re

all: $(C_NAME)

$(C_NAME): $(C_OBJ)
	@$(CC) $(OBJ) -o $(C_NAME)
	@echo $(GREEN)$(C_NAME) Build done!$(RESET)

$(CHECKER_DIR)%.o: $(CHECKER_DIR)%.c
	@$(CC) $(FLAGS) -I $(CHECKER_HEADER) -c $< -o $@
	@echo $(CYAN)Compiling... $<$(RESET)

clean:
	@rm -rf $(OBJ)
	@echo $(RED)Object files was deleted$(RESET)

fclean: clean
	@rm -rf $(PS_NAME) $(C_NAME)
	@echo $(RED)$(PS_NAME) $(C_NAME) was deleted$(RESET)

re: fclean all
