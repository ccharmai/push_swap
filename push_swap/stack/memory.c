/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 16:49:03 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/13 16:38:50 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	free_stack(t_stack *stack)
{
	t_stack	*prev;
	t_stack	*p;

	prev = NULL;
	while (stack->next)
	{
		prev = stack;
		stack = stack->next;
		free(prev);
	}
	free(stack);
}

int		stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

int		have_two(t_stack *stack)
{
	if (stack && stack->next)
		return (1);
	return (0);
}