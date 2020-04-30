/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_3_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 19:46:56 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/30 20:18:49 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	*stack_2_mass(int len, t_stack *a)
{
	int i;
	int	*mass;

	mass = (int*)malloc(sizeof(int) * len);
	if (!mass)
		raise_memory_error();
	i = 0;
	while (i < len)
	{
		mass[i] = a->element;
		i++;
		a = a->next;
	}
	return (mass);
}

int	*find_3_points(t_stack *a)
{
	int	len;
	int step;
	int	*mass;
	int *points;

	len = stack_len(a);
	mass = stack_2_mass(len, a);
	ft_qsort(len, mass);
	step = len / 4;
	points = (int*)malloc(sizeof(int) * 3);
	if (!points)
		raise_memory_error();
	points[0] = mass[step];
	points[1] = mass[step * 2];
	points[2] = mass[step * 3];
	return (points);
}
