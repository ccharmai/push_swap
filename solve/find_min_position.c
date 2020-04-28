/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 20:41:10 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/28 20:43:08 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	find_min_position(t_stack *stack)
{
	int	min;
	int position;
	int i;

	min = stack->element;
	position = 0;
	i = 0;
	while (stack)
	{
		if (stack->element < min)
		{
			min = stack->element;
			position = i;
		}
		stack = stack->next;
		i++;
	}
	return (position);
}
