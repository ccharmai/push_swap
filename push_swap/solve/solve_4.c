/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 20:40:58 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/16 09:35:42 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	solve_4(t_stack **a)
{
	t_stack	*b;
	int	flag;

	flag = 1;
	b = NULL;
	move_one_smaller(&(*a), &b);
	solve_3(&(*a));
	push(&b, &(*a), flag);
}
