/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 19:20:37 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/20 20:09:29 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	raise_not_integer_error(void)
{
	write(1, "Error: not integer\n", 19);
	exit(1);
}

void	raise_not_unique_error(void)
{
	write(1, "Error unique\n", 13);
	exit(1);
}

void	raise_memory_error(void)
{
	write(1, "Memory error detected\n", 22);
	exit(1);
}
