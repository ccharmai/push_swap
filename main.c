/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 17:11:33 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/27 19:08:27 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int	main()
{
	// test_stack();
	// t_stack	*a;
	// // t_stack	*b;

	// a = generate_stack_a();
	// ft_printf("stack a:\n");
	// print_stack(a);

	int mass_a[] = {1, 2, 3};
	t_stack *a = init_stack_with_mass(3, mass_a);

	int mass_b[] = {4, 5, 6};
	t_stack *b = init_stack_with_mass(3, mass_b);

	push(&a, &b);
	push(&a, &b);
	swap(a);

	rotate(&a);
	rotate(&b);

	print_stack(a);
	print_stack(b);

	reverse_rotate(&b);

	print_stack(b);

	free_stack(a);
	free_stack(b);
	return 0;
}
