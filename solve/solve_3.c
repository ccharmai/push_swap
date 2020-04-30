/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 21:26:45 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/30 16:01:12 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	solve_3(t_stack **a)
{
	int		first;
	int		second;
	int		third;

	first = (*a)->element;
	second = (*a)->next->element;
	third = (*a)->next->next->element;
	if (is_sorted(*a))
	{
		return ;
	}
	else if (first > second && second < third && first < third)
	{
		swap(*a);
	}
	else if (first > second && second > third && third < first)
	{
		swap(*a);
		reverse_rotate(&(*a));
	}
	else if (first > second && second < third && third < first)
	{
		rotate(&(*a));
	}
	else if (first < second && third < second && third > first)
	{
		swap(*a);
		rotate(&(*a));
	}
	else if (first < second && second > third && third < first)
	{
		reverse_rotate(&(*a));
	}
}
