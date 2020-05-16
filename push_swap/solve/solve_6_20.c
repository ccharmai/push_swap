/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_6_20.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 21:18:30 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/16 11:14:13 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	move_2_b(t_stack **a, t_stack **b, int flag)
{
	while (*a)
		push(&(*a), &(*b), flag);
}

void	prtmover(t_stack **b, int up, int down)
{
	int i;
	int	flag;

	flag = 2;
	i = 0;
	if (up < down)
		while (i < up)
		{
			rotate(&(*b), flag);
			i++;
		}
	else
		while (i < down)
		{
			reverse_rotate(&(*b), flag);
			i++;
		}
}

void	mover(t_stack **a, t_stack **b, int flag)
{
	int		up;
	int		down;
	int		i;
	int		if_min;
	t_pos	info;

	flag = 1;
	info = get_position_info(*b);
	up = info.min_position <= info.max_position ? \
	info.min_position : info.max_position;
	down = up == info.max_position ? info.min_position : info.max_position;
	if_min = 0;
	prtmover(&(*b), up, down);
	if ((*b)->element == info.min_element)
		if_min = 1;
	push(&(*b), &(*a), flag);
	if (if_min)
		rotate(&(*a), flag);
}

void	solve_6_20(t_stack **a)
{
	t_stack *b;
	t_pos	info;
	int		flag;

	flag = 2;
	b = NULL;
	move_2_b(&(*a), &b, flag);
	while (b)
		mover(&(*a), &b, flag);
	flag = 1;
	info = get_position_info(*a);
	while ((*a)->element != info.min_element)
		rotate(&(*a), flag);
}
