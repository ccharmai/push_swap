/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 17:11:27 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/16 11:11:55 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../ft_printf/includes/printf.h"

typedef struct			s_stack
{
	int					index;
	int					element;
	struct s_stack		*next;
}						t_stack;

typedef struct			s_pos
{
	int					min_position;
	int					min_element;
	int					max_position;
	int					max_element;
}						t_pos;

void					raise_not_integer_error();
void					raise_not_unique_error(void);
int						is_integer(char *line);
void					print_both_stack(t_stack *a, t_stack *b);
int						get_largest_width(t_stack *stack);
void					print_n_spaces(int n);
void					print_init(t_stack *a);
int						is_sorted(t_stack *stack);
void					print_answer(t_stack *a);
int						check_unique_int_mass(int len, int *mass);
void					pass(void);

void					swap(t_stack *stack, int flag);
void					push(t_stack **rem_head, t_stack **get_head, int flag);
void					rotate(t_stack **stack, int flag);
void					reverse_rotate(t_stack **stack, int flag);

t_stack					*create_head(int element);
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
t_pos					get_position_info(t_stack *stack);
void					ft_qsort(int len, int *mass);

void					move_one_smaller(t_stack **a, t_stack **b);
int						*find_3_points(t_stack *a);
void					move_2_b(t_stack **a, t_stack **b, int flag);
void					switcher(t_stack *a);
void					solve_2(t_stack **a);
void					solve_3(t_stack **a);
void					solve_4(t_stack **a);
void					solve_5(t_stack **a);
void					solve_6_20(t_stack **a);
void					solve_21_101(t_stack **a);
int						*find_index(t_stack *a);
void					push_back(t_stack **a, t_stack **b, int flag);
void					check_seq(t_stack **a, t_stack *b, int len);
void					mover(t_stack **a, t_stack **b, int flag);
void					solve101plus(t_stack **a);
t_stack					*less_than_2_b(int *point, t_stack **a);
void					mover100(t_stack **a, t_stack **b, int len, int n);
t_pos					get_position(t_stack *stack, int len);
void					solve102(t_stack **a, int len);
void					solve103(t_stack **a, int len);
void					fixit(t_stack **a, int len, int n);
void					solve104(t_stack **a, int len);
void					fixit1(t_stack **a, int len);
void					solve105(t_stack **a, int len);
t_pos					get_position3(t_stack *stack, t_stack *stack2, int len);
t_pos					get_position2(t_stack *stack, int len);

#endif
