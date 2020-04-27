/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 16:50:20 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/27 17:25:33 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	test_stack(void)
{
	int mass[] = {4, 5, 6, 7, 8, 3, 3, 2, 5, 6};
	int len_mass = 10;
	t_stack	*stack_from_mass = init_stack_with_mass(len_mass,  mass);

	ft_printf("print stack from mass\n");
	print_stack(stack_from_mass);

	int n = delete_element(stack_from_mass, 32423);
	print_stack(stack_from_mass);
	ft_printf("was deleted %i\n", n);

	free_stack(stack_from_mass);
}
