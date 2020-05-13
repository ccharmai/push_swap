/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unique.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 17:42:29 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/13 17:46:44 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_unique_int_mass(int len, int *mass)
{
	int	i;
	int	z;

	i = 0;
	if (len == 1)
		return (1);
	while (i < len - 1)
	{
		z = i + 1;
		while (z < len)
		{
			if (mass[i] == mass[z])
				return (0);
			z++;
		}
		i++;
	}
}
