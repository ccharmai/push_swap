/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:06:24 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/13 17:07:36 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	push_back(t_stack **a, t_stack **b)
{
	push(&(*b), &(*a));
}

void	push_back2(t_stack **a, t_stack **b)
{
	push(&(*a), &(*b));
}

void	check_seq(t_stack **a, t_stack *b, int len)
{
	int		i;
	int		n;
	t_stack	*tmp;

	tmp = *a;
	i = 0;
	while (tmp)
	{
		if (tmp->element + 1 == tmp->next->element)
			tmp = tmp->next;
		else
			break ;
		i++;
	}
	while (tmp->element == i)
		tmp = tmp->next;
	while ((i + 1) < len)
	{
		reverse_rotate(a);
		i++;
	}
	i = 0;
	while (i < (len / 2))
	{
		push_back2(&(*a), &b);
		i++;
	}
	while (b)
		mover(&(*a), &b);
}
