/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 21:07:10 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/18 13:08:17 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	solve_b(t_stack **a, t_stack **b)
{
	int		if_min;
	int		counter = 0;
	int		i = 0;
	int		up;
	int		down;
	t_pos	info;

	while (*b)
	{
		info = get_position_info(*b);
		up = info.min_position <= info.max_position ? info.min_position : info.max_position;
		down = up == info.max_position ? info.min_position : info.max_position;
		i = 0;
		if_min = 0;
		if ((info.len - down) >= up)
			while (i < up)
			{
				rotate(&(*b), 'b');
				i++;
			}
		else
			while (i < (info.len - down))
			{
				reverse_rotate(&(*b), 'b');
				i++;
			}
		if ((*b)->element == info.min_element)
			if_min = 1;
		push(&(*b), &(*a), 'a');
		if (if_min)
			rotate(&(*a), 'a');
		else
			counter++;
	}
	i = 0;
	while (i < counter)
	{
		rotate(&(*a), 'a');
		i++;
	}
}

void mysolve(t_stack **a, int col_blocks)
{
	t_stack	*b = NULL;
	int len = stack_len(*a);
	int *mass = stack_2_mass(len, *a);
	ft_qsort(len, mass);
	int step = len / col_blocks;
	int i = 0;

	while (i < len)
	{
		if ((*a)->element < mass[step])
			push(&(*a), &b, 'b');
		else
			rotate(&(*a), 'a');
		i++;
	}
	solve_b(&(*a), &b);
	for (int k = 1; k < col_blocks - 1; k++)
	{
		i = 0;
		while (i < (len - step * k))
		{
			if ((*a)->element < mass[step * (k + 1)])
				push(&(*a), &b, 'b');
			else
				rotate(&(*a), 'a');
			i++;
		}
		for (int i = 0; i < (step * k); i++)
			rotate(&(*a), 'a');
		solve_b(&(*a), &b);
	}
	i = 0;
	while (i < (len - step * (col_blocks - 1)))
	{
		push(&(*a), &b, 'b');
		i++;
	}
	solve_b(&(*a), &b);
	free(mass);
}

void	switcher(t_stack *a)
{
	int len;

	len = stack_len(a);
	if (len == 1)
		pass();
	else if (len == 2)
		solve_2(&a);
	else if (len == 3)
		solve_3(&a);
	else if (len == 4)
		solve_4(&a);
	else if (len == 5)
		solve_5(&a);
	else if (len >= 6 && len <= 120)
		mysolve(&a, 3);
	else if (len > 120 && len <= 180)
		mysolve(&a, 4);
	else if (len > 180 && len <= 300)
		mysolve(&a, 5);
	else if (len > 300 && len <= 520)
		mysolve(&a, 6);
	else if (len > 520 && len <= 700)
		mysolve(&a, 7);
	else if (len > 700 && len <= 880)
		mysolve(&a, 8);
	else if (len > 880 && len <= 1120)
		mysolve(&a, 9);
	else if (len > 1120 && len <= 1360)
		mysolve(&a, 10);
	else if (len > 1360 && len <= 1660)
		mysolve(&a, 11);
	else if (len > 1660 && len <= 1960)
		mysolve(&a, 12);
	else
		mysolve(&a, 13);
	free_stack(a);
}
