/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve101plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:16:22 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/13 17:18:55 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	push_back3(t_stack **a, t_stack **b)
{
	push(&(*a), &(*b));
}

void	ch_seq(t_stack **a, t_stack *b, int len)
{
	int		i;
	int		n;
	t_stack	*tmp;

	tmp = *a;
	i = 0;
	n = len / 4;
	while (i < n)
	{
		if (tmp->next->element - tmp->element >= 0)
			tmp = tmp->next;
		else
			break ;
		i++;
	}
	while (i < len)
	{
		reverse_rotate(a);
		i++;
	}
	i = 1;
	n = len / 4;
}

void	mover101(t_stack **a, t_stack **b, int len, int n)
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

void	solve101adop(t_stack **a, int *point, int len)
{
	t_pos	info;
	t_stack	*tmpa;
	int		i;
	int		n;
	int		z;
	t_stack	*b;

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
	z = len / 4 + 1;
	while (i < z)
	{
		mover100(&(*a), &b, len, n);
		i++;
		n--;
	}
	i = 0;
	while (i < z)
	{
		push_back(&(*a), &b);
		i++;
	}
	ch_seq(&(*a), b, len);
}

void	solve101plus(t_stack **a)
{
	int		*points;
	int		len;
	int		i;
	t_stack	*half_sort;

	i = 0;
	points = find_index(*a);
	len = stack_len(*a);
	solve101adop(&(*a), points, len);
	solve102(&(*a), points, len);
	solve103(&(*a), points, len);
	free(points);
}
