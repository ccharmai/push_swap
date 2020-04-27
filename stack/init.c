/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 16:49:54 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/27 17:11:06 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*create_head(int element)
{
	t_stack	*head;

	head = (t_stack*)malloc(sizeof(t_stack));
	if (!head)
		raise_memory_error();
	head->element = element;
	head->next = NULL;
	return (head);
}

void	append_element(int element, t_stack *stack)
{
	t_stack	*p;
	t_stack	*tmp;

	p = stack;
	while (p->next)
		p = p->next;
	tmp = (t_stack*)malloc(sizeof(t_stack));
	if (!tmp)
		raise_memory_error();
	tmp->element = element;
	tmp->next = NULL;
	p->next = tmp;
}

t_stack	*init_stack_with_mass(int len, int *mass)
{
	t_stack	*head;
	t_stack *tmp_head;
	int		i;

	i = 0;
	tmp_head = create_head(0);
	while (i < len)
	{
		append_element(mass[i], tmp_head);
		i++;
	}
	head = tmp_head->next;
	free(tmp_head);
	return (head);
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%i ", stack->element);
		stack = stack->next;
	}
	ft_printf("\n");
}
