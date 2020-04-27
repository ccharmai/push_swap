/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 21:26:45 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/27 22:04:28 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	solve_3(t_stack *a)
{
	t_stack *b;
	int		first;
	int		second;
	int		third;

	first = a->element;
	second = a->next->element;
	third = a->next->next->element;
	b = NULL;

	if (is_sorted(a))
	{
		ft_printf("Exec:\n");
		print_both_stack(a, b);
	}

	else if (second < first && first < third)
	{
		ft_printf("Exec: sa\n");
		swap(a);
		print_both_stack(a, b);
	}

	else if (third < second && second < third)
	{
		ft_printf("Exec: sa rra\n");
		swap(a);
		reverse_rotate(&a);
		print_both_stack(a, b);
	}

	else if (second < third && third < first)
	{
		ft_printf("Exec: ra\n");
		rotate(&a);
		print_both_stack(a, b);
	}

	else if (first < third && third < second)
	{
		ft_printf("Exec: sa ra\n");
		swap(a);
		rotate(&a);
		print_both_stack(a, b);
	}

	else if (third < first && first < second)
	{
		ft_printf("Exec: ra\n");
		reverse_rotate(&a);
		print_both_stack(a, b);
	}

	else if (second < first)
	{
		ft_printf("Exec: sa\n");
		swap(a);
		print_both_stack(a, b);
	}
}
