/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_21_101.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 22:21:24 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/01 15:25:22 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	less_than_2_b(int point, t_stack **a, t_stack **b)
{
	int	len;
	int	i;

	i = 0;
	len = stack_len(*a);
	while (i < len)
	{
		if ((*a)->element < point)
			push(&(*a), &(*b));
		rotate(&(*a));
		i++;
	}
}

void	solve_21_101(t_stack **a)
{
	int		*points;
	t_stack	*b;

	b = NULL;
	points = find_3_points(*a);
	// less_than_2_b(points[0], &(*a), &b);

	// print_stack(b);
	solve_6_20(&(*a));
	print_both_stack(*a, b);
	// print_stack(b);

	free(points);
}
