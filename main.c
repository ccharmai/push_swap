/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 17:11:33 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/27 21:39:03 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack	*b;

	a = init_stack_with_char_mass(ac, av);
	// b = init_stack_with_char_mass(ac, av);

	// print_stack_stolb(a);

	// print_init(a);
	// ft_printf("\n");

	switcher(a);

	// print_both_stack(a, b);

	// ft_printf("check that a is sorted\n");
	// if (is_sorted(a))
	// 	ft_printf("Sorted!\n");
	// else
	// 	ft_printf("no, sorry :(\n");

	free_stack(a);
	// free_stack(b);

	return 0;
}
