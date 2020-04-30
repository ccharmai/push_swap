/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 19:28:17 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/30 19:39:09 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	ft_qsort(int len, int *mass)
{
	int i = 0;
	int j = len - 1;
	int tmp;

	int mid = mass[len / 2];
	while (i <= j)
	{
		while (mass[i] < mid)
			i++;
		while (mass[j] > mid)
			j--;
		if (i <= j)
		{
			tmp = mass[i];
			mass[i] = mass[j];
			mass[j] = tmp;

			i++;
			j--;
		}
	}
	if (j > 0)
		ft_qsort(j + 1, mass);
	if (i < len)
		ft_qsort(len - i, &mass[i]);
}
