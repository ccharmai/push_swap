/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crud.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 17:17:07 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/27 17:26:27 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	delete_element(t_stack *stack, int number)
{
	int		i;
	int		n;
	t_stack	*p;
	t_stack	*prev;

	i = 0;
	p = stack;
	prev = NULL;
	while (p->next && i < number)
	{
		prev = p;
		p = p->next;
		i++;
	}
	prev->next = p->next;
	n = p->element;
	free(p);
	return (n);
}
