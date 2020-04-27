#ifndef STACK_H
# define STACK_H

# include "../includes/header.h"

typedef struct			t_stack
{
	int					element;
	struct t_stack		*next;
}						s_stack;

// standart stack's functions here

s_stack			*create_head(int element);
void			test_stack();
void			free_stack(s_stack *stack);

s_stack			*init_stack_with_mass(int len, int *mass);
void			print_stack(s_stack *stack);

#endif