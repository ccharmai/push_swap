/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 18:02:22 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/27 18:07:18 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

t_stack	*generate_stack_a()
{
	int		len;
	int		i;
	t_stack	*head;
	t_stack	*out;

	i = 0;
	len = 15;
	head = create_head(0);
	while (i < len)
	{
		append_element(17, head);
		i++;
	}
	out = head->next;
	free (head);
	return (out);
}
