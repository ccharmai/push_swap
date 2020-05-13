/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve102.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:11:31 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/13 17:13:57 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_pos	get_position3(t_stack *stack, t_stack *stack2, int len, int n)
{
	int		i;
	t_pos	info;

	info.min_element = stack->element;
	i = 0;
	while (stack)
	{
		if (stack->element > len / 4 && (stack->element == stack2->element + 1))
			info.min_position = i;
		stack = stack->next;
		i++;
	}
	return (info);
}

t_pos	get_position2(t_stack *stack, int len, int n)
{
	int		i;
	t_pos	info;

	info.min_element = stack->element;
	i = 0;
	while (stack)
	{
		if (stack->element <= info.min_element && stack->element >= (len / 4))
		{
			info.min_element = stack->element;
			info.min_position = i;
		}
		i++;
		stack = stack->next;
	}
	return (info);
}

void	fixit(t_stack **a, int len, int st_a)
{
	int		need;
	int		mash1;
	int		mash2;
	int		i;
	t_pos	info;
	t_stack *tmp;

	info = get_position(*a, len);
	need = info.min_position + len / 4;
	mash1 = info.min_position;
	mash2 = st_a - need;
	i = 0;
	tmp = (*a);
	if (mash1 > mash2)
	{
		while (i < need)
		{
			tmp = tmp->next;
			i++;
		}
		while (i < st_a)
		{
			reverse_rotate(&(*a));
			i++;
		}
	}
	else
	{
		while (i < need)
		{
			rotate(&(*a));
			i++;
		}
	}
}

void	mover102(t_stack **a, t_stack **b, int len, int n)
{
	int		up;
	int		down;
	int		i;
	t_pos	info;

	if ((*a)->element < len / 4)
		info = get_position3(*a, *b, len, n);
	else
		info = get_position2(*a, len, n);
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

void	solve102(t_stack **a, int *point, int len)
{
	t_pos	info;
	t_stack	*tmpa;
	int		i;
	int		n;
	int		z;
	t_stack	*b;

	b = NULL;
	i = 0;
	n = len;
	z = len / 4;
	while (i < z)
	{
		mover102(&(*a), &b, len, n);
		i++;
		n--;
	}
	fixit(&(*a), len, n);
	while (b)
	{
		push(&b, &(*a));
		i--;
	}
	while (i < (len / 4))
	{
		rotate(&(*a));
		i++;
	}
}
