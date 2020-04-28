/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 21:07:10 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/28 20:44:14 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	switcher(t_stack *a)
{
	int len;

	len = stack_len(a);
	if (len == 1)
		solve_1(a);
	else if (len == 2)
		solve_2(a);
	else if (len == 3)
		solve_3(a);
	else if (len == 4)
		solve_4(a);
	else if (len == 5)
		ft_printf("len = 5\n");
}
