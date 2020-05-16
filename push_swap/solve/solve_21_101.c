/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_21_101.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 16:59:07 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/16 10:24:41 by lnoisome         ###   ########.fr       */
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
	int		flag;

	flag = 1;
	info = get_position(*a, len);
	up = info.min_position;
	down = n - info.min_position;
	i = 0;
	if (up < down)
		while (i < up)
		{
			rotate(&(*a), flag);
			i++;
		}
	else
		while (i < down)
		{
			reverse_rotate(&(*a), flag);
			i++;
		}
	flag = 2;
	push(&(*a), &(*b), flag);
}

void	solve_6_20adop(t_stack **a, int *point, int len)
{
	t_stack	*tmpa;
	t_stack *b;
	int		i;
	int		n;
	int		flag;

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
	while (i++ < (len / 2))
	{
		mover100(&(*a), &b, len, n);
		n--;
	}
	i = 0;
	flag = 1;
	while (i++ < (len / 2))
		push_back(&(*a), &b, flag);
	check_seq(&(*a), b, len);
}

void	solve_21_101(t_stack **a)
{
	int		*points;
	int		i;
	int		len;

	i = 0;
	points = find_index(*a);
	len = stack_len(*a);
	solve_6_20adop(&(*a), points, len);
	free(points);
}
