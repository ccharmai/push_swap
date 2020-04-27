/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 17:11:27 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/27 18:10:46 by ccharmai         ###   ########.fr       */
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

// libs functions here
void					raise_out_of_stack_error();

// push swap functions here
t_stack					*generate_stack_a();

// stack functions here
t_stack					*create_head(int element);
void					test_stack();
void					free_stack(t_stack *stack);
t_stack					*init_stack_with_mass(int len, int *mass);
void					print_stack(t_stack *stack);
int						delete_element(t_stack **stack, int i);
int						delete_head(t_stack **head);
int						delete_last(t_stack *stack);
void					append_element(int element, t_stack *stack);
int						stack_len(t_stack *stack);

#endif
