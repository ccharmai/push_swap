lib:
	@cd ./ft_printf && make
	@cd ./ft_printf && make clean

all: lib
	@gcc *.c /libs/*.c /stack/*.c -L. ./ft_printf/libftprintf.a -I includes/header.h -o prog

clean:
	@cd ./ft_printf && make clean

fclean:
	@rm -rf prog
	@cd ./ft_printf && make fclean

test:
	@gcc *.c ./libs/*.c ./stack/*.c -L. ./ft_printf/libftprintf.a -I includes/header.h -o prog
	@./prog 2 6 3 6 4 2 6 156

grind:
	@gcc -g *.c ./libs/*.c ./stack/*.c -L. ./ft_printf/libftprintf.a -I includes/header.h -o prog
	@valgrind --leak-check=full ./prog 43 23 56 87 34
