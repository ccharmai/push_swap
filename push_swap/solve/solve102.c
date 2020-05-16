/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve102.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:11:31 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/16 11:10:13 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	ifelse(t_stack **a, int i, int need, int st_a)
{
	t_stack	*tmp;
	t_pos	info;
	int		flag;

	flag = 1;
	tmp = (*a);
	if (info.min_position > (st_a - need))
	{
		while (i < need)
		{
			tmp = tmp->next;
			i++;
		}
		while (i < st_a)
		{
			reverse_rotate(&(*a), flag);
			i++;
		}
	}
	else
	{
		while (i < need)
		{
			rotate(&(*a), flag);
			i++;
		}
	}
}

void	fixit(t_stack **a, int len, int st_a)
{
	int		need;
	int		i;
	t_pos	info;
	t_stack *tmp;

	info = get_position(*a, len);
	need = info.min_position + len / 4;
	i = 0;
	tmp = (*a);
	ifelse(&(*a), i, need, st_a);
}

void	mover102(t_stack **a, t_stack **b, int len, int n)
{
	int		up;
	int		down;
	int		i;
	t_pos	info;
	int		flag;

	if ((*a)->element < len / 4)
		info = get_position3(*a, *b, len);
	else
		info = get_position2(*a, len);
	up = info.min_position;
	down = n - info.min_position;
	i = 0;
	flag = 1;
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

void	solve102(t_stack **a, int len)
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
		mover102(&(*a), &b, len, n);
		i++;
		n--;
	}
	fixit(&(*a), len, n);
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
