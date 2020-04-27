/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 16:50:20 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/27 18:11:04 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	test_stack(void)
{
	int mass[] = {4, 5, 6, 7, 8, 3, 3, 2, 5, 6};
	int len_mass = 10;
	t_stack	*stack_from_mass = init_stack_with_mass(len_mass,  mass);

	ft_printf("original stack\n");
	print_stack(stack_from_mass);
	ft_printf("\n");

	int n = delete_element(&stack_from_mass, 0);
	print_stack(stack_from_mass);
	ft_printf("was deleted %i\n\n", n);

	n = delete_element(&stack_from_mass, 1);
	print_stack(stack_from_mass);
	ft_printf("was deleted %i\n\n", n);

	n = delete_element(&stack_from_mass, 100);
	print_stack(stack_from_mass);
	ft_printf("was deleted %i\n\n", n);

	n = delete_element(&stack_from_mass, 100);
	print_stack(stack_from_mass);
	ft_printf("was deleted %i\n\n", n);

	n = delete_last(stack_from_mass);
	print_stack(stack_from_mass);
	ft_printf("was deleted %i\n\n", n);

	ft_printf("length of out stack = %i\n", stack_len(stack_from_mass));

	free_stack(stack_from_mass);
}
