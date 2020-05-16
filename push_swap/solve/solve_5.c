/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:06:02 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/16 09:37:21 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	move_one_smaller(t_stack **a, t_stack **b)
{
	int		i;
	t_pos	info;
	int		flag;

	flag = 1;
	info = get_position_info(*a);
	i = 0;
	if (info.min_position <= 3)
	{
		while (i < info.min_position)
		{
			rotate(&(*a), flag);
			i++;
		}
	}
	else
		while (i < (5 - info.min_position))
		{
			reverse_rotate(&(*a), flag);
			i++;
		}
	flag = 2;
	push(&(*a), &(*b), flag);
}

void	move_two_smaller(t_stack **a, t_stack **b)
{
	move_one_smaller(&(*a), &(*b));
	move_one_smaller(&(*a), &(*b));
}

void	solve_5(t_stack **a)
{
	t_stack	*b;
	int flag;

	flag = 1;
	b = NULL;
	move_two_smaller(&(*a), &b);
	solve_3(&(*a));
	push(&b, &(*a), flag);
	push(&b, &(*a), flag);
}
