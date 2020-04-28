/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 20:35:09 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/28 20:38:10 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	solve_2(t_stack *a)
{
	t_stack	*b;

	b = NULL;
	if (is_sorted(a))
		print_both_stack(a, b);
	else
	{
		ft_printf("Exec: sa\n");
		swap(a);
		print_both_stack(a, b);
	}
}
