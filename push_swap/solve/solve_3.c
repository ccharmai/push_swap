/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 21:26:45 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/16 11:10:36 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	solve_3(t_stack **a)
{
	int		first;
	int		second;
	int		third;
	int		flag;

	flag = 1;
	first = (*a)->element;
	second = (*a)->next->element;
	third = (*a)->next->next->element;
	if (is_sorted(*a))
		return ;
	else if (first > second && second < third && first < third)
		swap(*a, flag);
	else if (first > second && second > third && third < first)
	{
		swap(*a, flag);
		reverse_rotate(&(*a), flag);
	}
	else if (first > second && second < third && third < first)
		rotate(&(*a), flag);
	else if (first < second && third < second && third > first)
	{
		swap(*a, flag);
		rotate(&(*a), flag);
	}
	else if (first < second && second > third && third < first)
		reverse_rotate(&(*a), flag);
}
