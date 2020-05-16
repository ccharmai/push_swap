/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve101plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:16:22 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/16 10:42:05 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	ch_seq(t_stack **a, t_stack *b, int len)
{
	int		i;
	int		n;
	t_stack	*tmp;
	int		flag;

	flag = 1;
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
		reverse_rotate(a, flag);
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

void	solve101part(t_stack **a, int *point, int len)
{
	int		i;
	t_stack	*tmpa;

	tmpa = (*a);
	i = 0;
	while (i < len)
	{
		tmpa->element = point[i];
		tmpa = tmpa->next;
		i++;
	}
}

void	solve101adop(t_stack **a, int *point, int len)
{
	t_pos	info;
	int		i;
	int		n;
	t_stack	*b;
	int flag;

	flag = 1;
	b = NULL;
	solve101part(&(*a), point, len);
	i = 0;
	n = len;
	while (i < (len / 4))
	{
		mover100(&(*a), &b, len, n);
		i++;
		n--;
	}
	i = 0;
	while (i < (len / 4))
	{
		push_back(&(*a), &b, flag);
		i++;
	}
	ch_seq(&(*a), b, len);
}

void	solve101plus(t_stack **a)
{
	int		*points;
	t_stack *half_sort;
	int		len;

	points = find_index(*a);
	len = stack_len(*a);
	solve101adop(&(*a), points, len);
	solve102(&(*a), len);
	solve103(&(*a), len);
	solve104(&(*a), len);
	solve105(&(*a), len);
	free(points);
}
