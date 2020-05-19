# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/19 19:32:13 by ccharmai          #+#    #+#              #
#    Updated: 2020/05/19 19:38:13 by ccharmai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = "\033[1;31m"
GREEN = "\033[1;32m"
RESET = "\033[0;0m"
CYAN = "\033[1;35m"

NAME = checker
HEADER = includes/

CC = gcc
FLAGS = -Wall -Werror -Wextra

ROOT_DIR = ./
ROOT_SRCS = ch_main.c \
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
ROOT_FILES = $(addprefix $(ROOT_DIR), $(ROOT_SRCS))

FILES_NAMES = $(ROOT_FILES)
FILES_NAMES = $(ROOT_SRCS)
OBJ = $(patsubst %.c, %.o, $(FILES_NAMES))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -I $(HEADER) $(OBJ) -o $(NAME)
	@echo $(GREEN)"Compilation done!"$(RESET)

%.o: %.c $(HEADER)/checker.h
	@echo $(CYAN)"Compiling... " $<$(RESET)
	@gcc $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@echo $(RED)"Object files was deleted"$(RESET)

fclean: clean
	@rm -rf $(NAME)
	@echo $(RED)$(NAME) "was deleted"$(RESET)

re: fclean all
