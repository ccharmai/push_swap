/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 20:16:54 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/27 20:19:17 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		is_sorted(t_stack *stack)
{
	t_stack	*prev;

	prev = NULL;
	while (stack)
	{
		if (prev && stack)
			if (stack->element < prev->element)
				return (0);
		prev = stack;
		stack = stack->next;
	}
	return (1);
}
