/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 19:28:58 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/27 19:44:50 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		get_width(int nb)
{
	int	w;

	w = 0;
	while (nb > 0)
	{
		w++;
		nb /= 10;
	}
	return (w);
}

int		get_largest_width(t_stack *stack)
{
	int max;
	int	tmp;

	max = 1;
	while (stack)
	{
		tmp = get_width(stack->element);
		if (tmp > max)
			max = tmp;
		stack = stack->next;
	}
	return (max);
}

void	print_n_spaces(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_printf(" ");
		i++;
	}
}

void	print_both_stack(t_stack *a, t_stack *b)
{
	int	width_max;

	width_max = get_largest_width(a);
	while (a || b)
	{
		if (a)
		{
			ft_printf("%i", a->element);
			print_n_spaces(width_max - get_width(a->element));
			a = a->next;
		}
		if (b)
		{
			ft_printf(" %i\n", b->element);
			b = b->next;
		}
	}
	ft_printf("_");
	print_n_spaces(width_max);
	ft_printf("_\n");
	ft_printf("a");
	print_n_spaces(width_max);
	ft_printf("b\n");
}