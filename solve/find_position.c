/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 20:41:10 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/28 22:40:08 by ccharmai         ###   ########.fr       */
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

int	find_max_position(t_stack *stack)
{
	int	min;
	int position;
	int i;

	min = stack->element;
	position = 0;
	i = 0;
	while (stack)
	{
		if (stack->element > min)
		{
			min = stack->element;
			position = i;
		}
		stack = stack->next;
		i++;
	}
	return (position);
}

int	find_min_element(t_stack *stack)
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
	return (min);
}

t_pos	*get_position_info(t_stack *stack)
{
	t_pos *info;

	info->min_position = 0;
	info->max_position = 0;
	
}
