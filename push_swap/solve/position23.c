/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position23.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:11:31 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/15 13:48:31 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_pos	get_position3(t_stack *stack, t_stack *stack2, int len)
{
	int		i;
	t_pos	info;

	info.min_element = stack->element;
	i = 0;
	while (stack)
	{
		if (stack->element > len / 4 && (stack->element == stack2->element + 1))
		{
			info.min_position = i;
		}
		stack = stack->next;
		i++;
	}
	return (info);
}

t_pos	get_position2(t_stack *stack, int len)
{
	int		i;
	t_pos	info;

	info.min_element = stack->element;
	i = 0;
	while (stack)
	{
		if (stack->element <= info.min_element && stack->element >= (len / 4))
		{
			info.min_element = stack->element;
			info.min_position = i;
		}
		i++;
		stack = stack->next;
	}
	return (info);
}
