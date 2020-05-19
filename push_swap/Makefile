# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/19 14:41:10 by ccharmai          #+#    #+#              #
#    Updated: 2020/05/19 19:29:12 by ccharmai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = "\033[1;31m"
GREEN = "\033[1;32m"
RESET = "\033[0;0m"
CYAN = "\033[1;35m"

NAME = push_swap
HEADER = includes/
INCLUDES = includes/header.h

CC = gcc
FLAGS = -Wall -Werror -Wextra

LIBS_DIR = libs/
LIBS_SRCS = check.c \
	errors.c \
	ft_atoi.c \
	is_integer.c \
	pass.c \
	qsort.c \
	unique.c
LIBS_FILES = $(addprefix $(LIBS_DIR), $(LIBS_SRCS))

SOLVE_DIR = solve/
SOLVE_SRCS = find_position.c \
	solve_2.c \
	solve_3.c \
	solve_4.c \
	solve_5.c \
	switcher.c
SOLVE_FILES = $(addprefix $(SOLVE_DIR), $(SOLVE_SRCS))

STACK_DIR = stack/
STACK_SRCS = crud.c \
	init.c \
	memory.c
STACK_FILES = $(addprefix $(STACK_DIR), $(STACK_SRCS))

ROOT_DIR = ./
ROOT_SRCS = functions.c \
	main.c
ROOT_FILES = $(addprefix $(ROOT_DIR), $(ROOT_SRCS))

FILES = $(LIBS_FILES) $(SOLVE_FILES) $(ROOT_FILES) $(STACK_FILES)
FILES_NAMES = $(LIBS_SRCS) $(SOLVE_SRCS) $(ROOT_SRCS) $(STACK_SRCS)
OBJ = $(patsubst %.c, %.o, $(FILES_NAMES))
DFILES = $(patsubst %.c, %.d, $(FILES_NAMES))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(OBJ) -I $(HEADER) -o $(NAME)
	@echo $(GREEN)"Compilation done!"$(RESET)

%.o: $(STACK_DIR)%.c $(HEADER)/header.h
	@echo $(CYAN)"Compiling... " $<$(RESET)
	@gcc $(FLAGS) -I $(HEADER) -o $@ -c $<

%.o: $(SOLVE_DIR)%.c $(HEADER)/header.h
	@echo $(CYAN)"Compiling... " $<$(RESET)
	@gcc $(FLAGS) -I $(HEADER) -o $@ -c $<

%.o: $(ROOT_DIR)%.c $(HEADER)/header.h
	@echo $(CYAN)"Compiling... " $<$(RESET)
	@gcc $(FLAGS) -I $(HEADER) -o $@ -c $<

%.o: $(LIBS_DIR)%.c $(HEADER)/header.h
	@echo $(CYAN)"Compiling... " $<$(RESET)
	@gcc $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@echo $(RED)"Object files was deleted"$(RESET)

fclean: clean
	@rm -rf $(NAME)
	@echo $(RED)$(NAME) "was deleted"$(RESET)

re: fclean all
