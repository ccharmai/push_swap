/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 19:20:37 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/13 17:50:35 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	raise_not_integer_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	raise_not_unique_error(void)
{
	ft_printf("Error unique\n");
	exit(1);
}
