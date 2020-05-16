/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:08:35 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/16 11:01:27 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_pos	get_position7(t_stack *stack, t_stack *stack2, int len)
{
	int		i;
	t_pos	info;

	info.min_element = stack->element;
	i = 0;
	while (stack)
	{
		if (stack->element > ((len / 4) + (len / 4) + (len / 4)) &&\
	(stack->element == stack2->element + 1))
		{
			info.min_position = i;
		}
		stack = stack->next;
		i++;
	}
	return (info);
}

t_pos	get_position6(t_stack *stack, int len)
{
	int		i;
	t_pos	info;

	info.min_element = stack->element;
	i = 0;
	while (stack)
	{
		if (stack->element <= info.min_element && \
	stack->element >= (len / 4) + (len / 4) + (len / 4))
		{
			{
				info.min_element = stack->element;
				info.min_position = i;
			}
		}
		i++;
		stack = stack->next;
	}
	return (info);
}

void	mover104(t_stack **a, t_stack **b, int len, int n)
{
	int		up;
	int		down;
	int		i;
	t_pos	info;
	int		flag;

	flag = 1;
	if ((*a)->element < ((len / 4) + (len / 4) + (len / 4)))
		info = get_position7(*a, *b, len);
	else
		info = get_position6(*a, len);
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

void	fixit4(t_stack **a, int len, int n, int flag)
{
	int		pos;
	int		down;
	int		i;
	t_pos	info;
	t_stack *tmp;

	info = get_position(*a, len);
	pos = info.min_position + (len / 4) + (len / 4) + (len / 4);
	tmp = (*a);
	i = 0;
	while (i < pos)
	{
		tmp = tmp->next;
		i++;
	}
	if (pos != n)
	{
		while (pos < n)
		{
			reverse_rotate(&(*a), flag);
			pos++;
		}
	}
}

void	solve104(t_stack **a, int len)
{
	t_stack	*tmpa;
	int		i;
	int		n;
	t_stack	*b;
	int		flag;

	flag = 1;
	b = NULL;
	i = 0;
	n = len;
	while (i < (len / 4))
	{
		mover104(&(*a), &b, len, n);
		i++;
		n--;
	}
	fixit4(&(*a), len, n, flag);
	while (b)
	{
		push(&b, &(*a), flag);
		i--;
	}
	while (i < (len / 4))
	{
		rotate(&(*a), flag);
		i++;
	}
}
