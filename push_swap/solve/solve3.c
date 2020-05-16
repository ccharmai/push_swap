/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:14:28 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/16 10:32:50 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_pos	get_position5(t_stack *stack, t_stack *stack2, int len)
{
	int		i;
	t_pos	info;

	info.min_element = stack->element;
	i = 0;
	while (stack)
	{
		if (stack->element >= ((len / 4) + (len / 4)) && \
	(stack->element == stack2->element + 1))
		{
			info.min_position = i;
		}
		stack = stack->next;
		i++;
	}
	return (info);
}

t_pos	get_position4(t_stack *stack, int len)
{
	int		i;
	t_pos	info;

	info.min_element = stack->element;
	i = 0;
	while (stack)
	{
		if (stack->element <= info.min_element &&\
	stack->element >= ((len / 4) + (len / 4)))
		{
			info.min_element = stack->element;
			info.min_position = i;
		}
		i++;
		stack = stack->next;
	}
	return (info);
}

void	fixit3(t_stack **a, int len, int n)
{
	int		pos;
	int		flag;
	int		i;
	t_pos	info;
	t_stack *tmp;

	flag = 1;
	info = get_position(*a, len);
	pos = info.min_position + len / 4 + len / 4;
	i = 0;
	tmp = (*a);
	while (i < pos)
	{
		(tmp) = (tmp)->next;
		i++;
	}
	while (i < n)
	{
		reverse_rotate(&(*a), flag);
		i++;
	}
}

void	mover103(t_stack **a, t_stack **b, int len, int n)
{
	int		up;
	int		down;
	int		i;
	t_pos	info;
	int		flag;

	flag = 1;
	if ((*a)->element < (len / 4) + (len / 4))
		info = get_position5(*a, *b, len);
	else
		info = get_position4(*a, len);
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

void	solve103(t_stack **a, int len)
{
	int		i;
	int		n;
	t_stack *b;
	int		flag;

	flag = 2;
	b = NULL;
	i = 0;
	n = len;
	while (i < (len / 4))
	{
		mover103(&(*a), &b, len, n);
		i++;
		n--;
	}
	fixit3(&(*a), len, n);
	while (b)
	{
		push(&b, &(*a), flag);
		i--;
	}
	flag = 1;
	while (i < len / 4)
	{
		rotate(&(*a), flag);
		i++;
	}
}
