/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:14:28 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/13 18:10:22 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_pos	get_position5(t_stack *stack, t_stack *stack2, int len, int n)
{
	int		i;
	t_pos	info;

	info.min_element = stack->element;
	i = 0;
	while (stack)
	{
		if (stack->element > (len / 2) && (stack->element == stack2->element + 1))
			info.min_position = i;
		stack = stack->next;
		i++;
	}
	return (info);
}

t_pos	get_position4(t_stack *stack, int len, int n)
{
	int		i;
	t_pos	info;

	info.min_element = stack->element;
	i = 0;
	while (stack)
	{
		if (stack->element <= info.min_element)
		{
			if (len < 750 && stack->element >= (len / 2) - 1)
			{
				info.min_element = stack->element;
				info.min_position = i;
			}
			else if (len > 750 && stack->element >= (len / 2) - 1)
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

void	fixit3(t_stack **a, int len)
{
	int		up;
	int		down;
	int		i;
	t_pos	info;

	info = get_position(*a, len);
	up = info.min_position;
	down = len - info.min_position;
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
}

void	mover103(t_stack **a, t_stack **b, int len, int n)
{
	int		up;
	int		down;
	int		i;
	t_pos	info;

	if ((*a)->element < len / 2)
		info = get_position5(*a, *b, len, n);
	else
		info = get_position4(*a, len, n);
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

void	solve103(t_stack **a, int *point, int len)
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
	z = (len / 4);
	while (i < z)
	{
		mover103(&(*a), &b, len, n);
		i++;
		n--;
	}
	free_stack(b);
}
