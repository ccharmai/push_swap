/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 17:11:27 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/28 22:37:53 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../ft_printf/includes/printf.h"

typedef struct			s_stack
{
	int					element;
	struct s_stack		*next;
}						t_stack;

typedef struct			s_pos
{
	int					min_position;
	int					max_position;
	int					max_position;
	int					max_element;
}						t_pos;

/*
*	libs functions here
*/
void					raise_not_integer_error();
int						is_integer(char *line);
void					print_both_stack(t_stack *a, t_stack *b);
int						get_largest_width(t_stack *stack);
void					print_n_spaces(int n);
void					print_init(t_stack *a);
int						is_sorted(t_stack *stack);

/* push swap functions here */
void					swap(t_stack *stack);
void					push(t_stack **rem_head, t_stack **get_head);
void					rotate(t_stack **stack);
void					reverse_rotate(t_stack **stack);

/* stack functions here */
t_stack					*create_head(int element);
void					test_stack();
void					free_stack(t_stack *stack);
t_stack					*init_stack_with_mass(int len, int *mass);
t_stack					*init_stack_with_char_mass(int len, char **av);
void					print_stack(t_stack *stack);
int						delete_element(t_stack **stack, int i);
int						delete_head(t_stack **head);
int						delete_last(t_stack *stack);
void					append_element(int element, t_stack *stack);
void					append_head(t_stack **stack, int element);
int						stack_len(t_stack *stack);
int						have_two(t_stack *stack);
int						find_min_position(t_stack *stack);
int						find_max_position(t_stack *stack);
int						find_min_element(t_stack *stack);

/* solve */
void					move_2_b(t_stack **a, t_stack **b);
void					switcher(t_stack *a);
void					solve_1(t_stack *a);
void					solve_2(t_stack *a);
void					solve_3(t_stack *a);
void					solve_4(t_stack *a);
void					solve_6_20(t_stack *a);
void					solve_21_101(t_stack *a);

#endif
