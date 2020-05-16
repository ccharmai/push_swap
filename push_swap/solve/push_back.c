/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:06:24 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/16 11:13:48 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	push_back(t_stack **a, t_stack **b, int flag)
{
	push(&(*b), &(*a), flag);
}

void	check_seq(t_stack **a, t_stack *b, int len)
{
	int		i;
	int		n;
	t_stack	*tmp;
	t_pos	info;
	int		flag;

	flag = 1;
	tmp = *a;
	i = len / 2;
	while (tmp->element == i)
		tmp = tmp->next;
	flag = 1;
	while ((i + 1) < len)
	{
		reverse_rotate(&(*a), flag);
		i++;
	}
	info = get_position(*a, len);
	i = 0;
	flag = 2;
	while (i++ < info.min_position)
		push(&(*a), &b, flag);
	while (b)
		mover(&(*a), &b, flag);
	flag = 1;
	info = get_position(*a, len);
	i = 0;
	while (i++ < info.min_position)
		rotate(&(*a), flag);
}
