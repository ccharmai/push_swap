lib:
	@cd ./ft_printf && make
	@cd ./ft_printf && make clean

all: lib
	@gcc *.c ./libs/*.c ./stack/*.c ./solve/*.c -L. ./ft_printf/libftprintf.a -I includes/header.h -o prog

clean:
	@cd ./ft_printf && make clean

fclean:
	@rm -rf prog
	@cd ./ft_printf && make fclean

test:
	@gcc *.c ./libs/*.c ./stack/*.c ./solve/*.c -L. ./ft_printf/libftprintf.a -I includes/header.h -o prog

grind:
	@gcc -g *.c ./libs/*.c ./stack/*.c ./solve/*.c -L. ./ft_printf/libftprintf.a -I includes/header.h -o prog
	@valgrind --leak-check=full ./prog ./prog 4 5 21 3 1 8
