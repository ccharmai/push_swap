/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 21:07:10 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/16 11:17:40 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	switcher(t_stack *a)
{
	int len;

	len = stack_len(a);
	if (len == 1)
		pass();
	else if (len == 2)
		solve_2(&a);
	else if (len == 3)
		solve_3(&a);
	else if (len == 4)
		solve_4(&a);
	else if (len == 5)
		solve_5(&a);
	else if (len >= 6 && len <= 20)
		solve_6_20(&a);
	else if (len >= 21 && len <= 101)
		solve_21_101(&a);
	else
		solve101plus(&a);
	free_stack(a);
}
