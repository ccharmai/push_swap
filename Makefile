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
	@./prog 6 3 5 4 1 7 2

grind:
	@gcc -g *.c ./libs/*.c ./stack/*.c ./solve/*.c -L. ./ft_printf/libftprintf.a -I includes/header.h -o prog
	@valgrind --leak-check=full ./prog 6 3 5 4 1 7 2
