/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_6_20.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 21:18:30 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/28 22:18:16 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	move_2_b(t_stack **a, t_stack **b)
{
	while (*a)
		push(&(*a), &(*b));
}

void	mover(t_stack **a, t_stack **b)
{
	int min_position = find_min_position(*b);
	int max_position = find_max_position(*b);

	int upper = min_position <= max_position ? min_position : max_position;
	int down = upper == max_position ? min_position : max_position;

	int i = 0;

	if (upper < down)
		{
			// if i choise up
			while (i < upper)
			{
				rotate(&(*b));
				i++;
			}
		}
	else
		{
			// if i choise down
			while (i < down)
			{
				reverse_rotate(&(*b));
				i++;
			}
		}
	int if_min = 0;
	if ((*b)->element == find_min_element(*b))
		if_min = 1;
	push(&(*b), &(*a));

	if (if_min)
		rotate(&(*a));
}

void	solve_6_20(t_stack *a)
{
	t_stack *b;

	b = NULL;
	move_2_b(&a, &b);
	while (b)
		mover(&a, &b);

	int min = find_min_element(a);
	while (a->element != min)
		rotate(&a);

	ft_printf("print stack a\n");
	print_stack(a);
}
