/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_integer_u.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:36:06 by sgalli            #+#    #+#             */
/*   Updated: 2022/11/09 15:37:45 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	lenght(unsigned int i, int c)
{
	while (i != 0)
	{
		c++;
		i = i / 10;
	}
	return (c);
}

int	unsigned_integer_u(unsigned int i)
{
	int	c;

	c = 0;
	c = c + lenght(i, c);
	if (i == 0)
	{
		c++;
		character_c('0');
	}
	else
	{
		if (i > 9)
		{
			unsigned_integer_u(i / 10);
			unsigned_integer_u(i % 10);
		}
		else
		{
			character_c(i + 48);
		}
	}
	return (c);
}
