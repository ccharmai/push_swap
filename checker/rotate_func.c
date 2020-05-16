/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 00:33:00 by lnoisome          #+#    #+#             */
/*   Updated: 2020/05/16 00:33:39 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

void	ra(t_folder **a)
{
	t_folder *tmp;

	if (*a)
	{
		tmp = *a;
		while ((*a)->next != NULL)
			*a = (*a)->next;
		(*a)->next = tmp;
		tmp = tmp->next;
		*a = (*a)->next;
		(*a)->next = NULL;
		*a = tmp;
	}
}

void	rb(t_folder **b)
{
	t_folder *tmp;

	if (*b)
	{
		tmp = *b;
		while ((*b)->next != NULL)
			*b = (*b)->next;
		(*b)->next = tmp;
		tmp = tmp->next;
		*b = (*b)->next;
		(*b)->next = NULL;
		*b = tmp;
	}
}

void	rr(t_folder **a, t_folder **b)
{
	if (*b && *a)
	{
		ra(a);
		rb(b);
	}
}
