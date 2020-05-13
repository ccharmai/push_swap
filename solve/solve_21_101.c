/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_21_101.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 16:59:07 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/13 17:27:35 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_pos	get_position(t_stack *stack, int len)
{
	int		i;
	t_pos	info;

	info.min_position = 0;
	info.min_element = stack->element;
	i = 0;
	while (stack)
	{
		if (stack->element < info.min_element)
		{
			info.min_element = stack->element;
			info.min_position = i;
		}
		i++;
		stack = stack->next;
	}
	return (info);
}

void	mover100(t_stack **a, t_stack **b, int len, int n)
{
	int		up;
	int		down;
	int		i;
	t_pos	info;

	info = get_position(*a, len);
	up = info.min_position;
	down = n - info.min_position;
	i = 0;
	if (up < down)
		while (i < up)
		{
			rotate(&(*a));
			i++;
		}
	else
		while (i < down)
		{
			reverse_rotate(&(*a));
			i++;
		}
	push(&(*a), &(*b));
}

void	solve_6_20adop(t_stack **a, int *point, int len)
{
	t_pos	info;
	t_stack	*tmpa;
	t_stack *b;
	int		i;
	int		n;

	b = NULL;
	i = 0;
	tmpa = (*a);
	while (i < len)
	{
		tmpa->element = point[i];
		tmpa = tmpa->next;
		i++;
	}
	i = 0;
	n = len;
	while (i < (len / 2))
	{
		mover100(&(*a), &b, len, n);
		i++;
		n--;
	}
	i = 0;
	while (i < (len / 2))
	{
		push_back(&(*a), &b);
		i++;
	}
	check_seq(&(*a), b, len);
	info = get_position_info(*a);
	while ((*a)->element != info.min_element)
		rotate(&(*a));
}

t_stack	*less_than_2_b(int *point, t_stack **a)
{
	int	len;
	int count;
	int	i;

	i = 0;
	count = 0;
	len = stack_len(*a);
	solve_6_20adop(&(*a), point, len);
	return (*a);
}

void	solve_21_101(t_stack **a)
{
	int		*points;
	int		i;
	t_stack *half_sort;

	i = 0;
	points = find_index(*a);
	half_sort = less_than_2_b(points, &(*a));
	free(points);
}
