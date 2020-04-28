/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_21_101.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 22:21:24 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/28 22:25:39 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/header.h"

void	solve_21_101(t_stack *a)
{
	t_stack *b;

	b = NULL;
	move_2_b(&(*a), &(*b));

	ft_printf("print stack a\n");
	print_stack(a);
	ft_printf("print stack b\n");
	print_stack(b);
}