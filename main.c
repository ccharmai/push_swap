/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 17:11:33 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/27 18:12:11 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

int	main()
{
	test_stack();
	t_stack	*a;
	// t_stack	*b;

	a = generate_stack_a();
	ft_printf("stack a:\n");
	print_stack(a);
	free_stack(a);
	return 0;
}
