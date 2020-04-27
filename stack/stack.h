/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 16:45:03 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/27 16:47:39 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "../includes/header.h"

typedef struct			s_stack
{
	int					element;
	struct s_stack		*next;
}						t_stack;

t_stack					*create_head(int element);
void					test_stack();
void					free_stack(t_stack *stack);
t_stack					*init_stack_with_mass(int len, int *mass);
void					print_stack(t_stack *stack);

#endif
