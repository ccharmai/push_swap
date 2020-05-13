/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_3_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 19:46:56 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/13 17:04:36 by ccharmai         ###   ########.fr       */
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

int	*find_index(t_stack *a)
{
	int *in_mass;
	int *mass;
	int	*tmp;
	int len;
	int i;
	int	n;
	int pos;
	int j;

	i = 0;
	len = stack_len(a);
	mass = stack_2_mass(len, a);
	in_mass = (int*)malloc(sizeof(int) * (len + 1));
	if (!in_mass)
		raise_memory_error();
	while (i < len)
	{
		in_mass[i] = mass[i];
		i++;
	}
	in_mass[i] = '\0';
	ft_qsort(len, in_mass);
	i = 0;
	while (in_mass[i])
	{
		if (in_mass[i] == (in_mass[i + 1]))
		{
			ft_printf("%i\n", in_mass[i]);
			ft_printf("%i\n", in_mass[i + 1]);
			ft_printf("error\n");
			exit(-1);
		}
		i++;
	}
	tmp = (int*)malloc(sizeof(int) * (len + 1));
	i = 0;
	n = 0;
	while (i < len)
	{
		j = 0;
		while (in_mass[j] != '\0')
		{
			if (mass[i] == in_mass[j])
			{
				tmp[n] = j;
				n++;
			}
			j++;
		}
		i++;
	}
	tmp[n] = '\0';
	free(in_mass);
	free(mass);
	return (tmp);
}
