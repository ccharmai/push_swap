/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_21_101.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 22:21:24 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/30 20:22:55 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	solve_21_101(t_stack **a)
{
	int *points;

	points = find_3_points(*a);
	ft_printf("general points = %i %i %i\n", points[0], points[1], points[2]);
	free(points);
}
