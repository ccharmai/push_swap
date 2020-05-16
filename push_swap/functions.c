/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 18:22:46 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/16 11:33:13 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	swap(t_stack *stack, int flag)
{
	int	tmp;

	if (!have_two(stack))
		return ;
	tmp = stack->element;
	stack->element = (stack->next)->element;
	(stack->next)->element = tmp;
	if (flag == 1)
		ft_printf("sa\n");
	else if (flag == 2)
		ft_printf("sb\n");
}

void	push(t_stack **rem_head, t_stack **get_head, int flag)
{
	if (!get_head || !rem_head)
		return ;
	append_head(get_head, delete_element(rem_head, 0));
	if (flag == 1)
		ft_printf("pa\n");
	else if (flag == 2)
		ft_printf("pb\n");
}

void	rotate(t_stack **stack, int flag)
{
	if (!have_two(*stack))
		return ;
	append_element(delete_head(&(*stack)), *stack);
	if (flag == 1)
		ft_printf("ra\n");
	else if (flag == 2)
		ft_printf("rb\n");
}

void	reverse_rotate(t_stack **stack, int flag)
{
	if (!have_two(*stack))
		return ;
	append_head(&(*stack), delete_last(*stack));
	if (flag == 1)
		ft_printf("rra\n");
	else if (flag == 2)
		ft_printf("rrb\n");
}
