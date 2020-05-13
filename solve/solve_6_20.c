/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_6_20.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 21:18:30 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/13 17:01:40 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	move_2_b(t_stack **a, t_stack **b)
{
	while (*a)
		push(&(*a), &(*b));
}

void	mover(t_stack **a, t_stack **b)
{
	int		up;
	int		down;
	int		i;
	int		if_min;
	t_pos	info;

	info = get_position_info(*b);
	up = info.min_position <= info.max_position ? \
	info.min_position : info.max_position;
	down = up == info.max_position ? info.min_position : info.max_position;
	i = 0;
	if (up < down)
		while (i < up)
		{
			rotate(&(*b));
			i++;
		}
	else
		while (i < down)
		{
			reverse_rotate(&(*b));
			i++;
		}
	if_min = 0;
	if ((*b)->element == info.min_element)
		if_min = 1;
	push(&(*b), &(*a));
	if (if_min)
		rotate(&(*a));
}

void	solve_6_20(t_stack **a)
{
	t_stack *b;
	t_pos	info;

	b = NULL;
	move_2_b(&(*a), &b);
	while (b)
		mover(&(*a), &b);
	info = get_position_info(*a);
	while ((*a)->element != info.min_element)
		rotate(&(*a));
}
