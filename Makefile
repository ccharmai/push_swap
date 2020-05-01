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
	@./prog -64 -61 92 30 -98 -65 -67 55 5 71 -50 9 -76 91 52 -71 -26 -33 46 90 -31 -10 11 -87 -79 -42 -96 32 86 15 -39 -55 -23 -95 -36 -17 80 63 65 99 69 -82 -30 -94 87 -73 53 17 77 -80 -14 -37 -88 81 -40 19 -100 33 -85 41 -51 -19 75 89 -89 10 88 58 -20 -54 -56 64 66 2 -75 -35 83 -86 -41 26 72 22 96 -62 -46 -11 47 48 -45 57 -59 -43 45 62 -49 98 -5 93 -22 8

grind:
	@gcc -g *.c ./libs/*.c ./stack/*.c ./solve/*.c -L. ./ft_printf/libftprintf.a -I includes/header.h -o prog
	@valgrind --leak-check=full ./prog -64 -61 92 30 -98 -65 -67 55 5 71 -50 9 -76 91 52 -71 -26 -33 46 90 -31 -10 11 -87 -79 -42 -96 32 86 15 -39 -55 -23 -95 -36 -17 80 63 65 99 69 -82 -30 -94 87 -73 53 17 77 -80 -14 -37 -88 81 -40 19 -100 33 -85 41 -51 -19 75 89 -89 10 88 58 -20 -54 -56 64 66 2 -75 -35 83 -86 -41 26 72 22 96 -62 -46 -11 47 48 -45 57 -59 -43 45 62 -49 98 -5 93 -22 8
