/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve105.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:08:35 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/16 11:12:58 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	solve105(t_stack **a, int len)
{
	int		i;
	t_pos	info;
	t_stack	*b;
	int		flag;

	flag = 2;
	b = NULL;
	i = 0;
	info = get_position((*a), len);
	while (i < info.min_position)
	{
		push(&(*a), &b, flag);
		i++;
	}
	while (b)
	{
		mover(&(*a), &b, flag);
		i--;
	}
	flag = 1;
	info = get_position((*a), len);
	while (i < info.min_position)
	{
		rotate(&(*a), flag);
		i++;
	}
}
