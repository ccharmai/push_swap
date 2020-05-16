/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 19:45:49 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/27 19:55:36 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	print_init(t_stack *a)
{
	int		w;
	t_stack	*p;

	p = a;
	ft_printf("Init a and b:\n");
	while (p)
	{
		ft_printf("%i\n", p->element);
		p = p->next;
	}
	w = get_largest_width(a);
	ft_printf("_");
	print_n_spaces(w);
	ft_printf("_\n");
	ft_printf("a");
	print_n_spaces(w);
	ft_printf("b\n");
}
