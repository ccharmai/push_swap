lib:
	@cd ./ft_printf && make
	@cd ./ft_printf && make clean

all: lib
	@gcc *.c -L. ./ft_printf/libftprintf.a -I includes/header.h -o prog

clean:
	@cd ./ft_printf && make clean

fclean:
	@rm -rf prog
	@cd ./ft_printf && make fclean

test:
	@gcc *.c -L. ./ft_printf/libftprintf.a -I includes/header.h -o prog
	@./prog

grind:
	@gcc -g *.c -L. ./ft_printf/libftprintf.a -I includes/header.h -o prog
	@valgrind --leak-check=full ./prog
