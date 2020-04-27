/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 18:22:46 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/27 19:07:17 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (!have_two(stack))
		return ;
	tmp = stack->element;
	stack->element = (stack->next)->element;
	(stack->next)->element = tmp;
}

void	push(t_stack **rem_head, t_stack **get_head)
{
	if (!get_head || !rem_head)
		return ;
	append_head(get_head, delete_element(rem_head, 0));
}

void	rotate(t_stack **stack)
{
	if (!have_two(*stack))
		return ;
	append_element(delete_head(&(*stack)), *stack);
}

void	reverse_rotate(t_stack **stack)
{
	if (!have_two(*stack))
		return ;
	append_head(&(*stack), delete_last(*stack));
}