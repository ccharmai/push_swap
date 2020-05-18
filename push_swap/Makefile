# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/18 13:04:51 by ccharmai          #+#    #+#              #
#    Updated: 2020/05/18 13:09:55 by ccharmai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@gcc -Wall -Werror -Wextra *.c ./libs/*.c ./stack/*.c ./solve/*.c -I includes/header.h -o push_swap

fclean:
	@rm -rf push_swap

grind:
	@gcc -Wall -Wall -g *.c ./libs/*.c ./stack/*.c ./solve/*.c -I includes/header.h -o push_swap
	@valgrind --leak-check=full ./push_swap `ruby -e "puts (-200..200).to_a.shuffle.join(' ')"` > /dev/null
