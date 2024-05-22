/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:36:51 by sgalli            #+#    #+#             */
/*   Updated: 2022/11/11 10:04:34 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexadecimal_x_xx(unsigned int i, int type)
{
	if (i >= 16)
	{
		hexadecimal_x_xx(i / 16, type);
		hexadecimal_x_xx(i % 16, type);
	}
	else if (i > 9)
	{
		if (type == 'X')
			character_c(i + 55);
		else
			character_c(i + 87);
	}
	else
		character_c(i + '0');
	return (i);
}

int	hexadecimal_x(unsigned int i, int type)
{
	unsigned int	c;

	c = 0;
	if (i == 0)
	{
		c += character_c('0');
		return (c);
	}
	else
	{
		hexadecimal_x_xx(i, type);
	}
	while (i != 0)
	{
		c++;
		i = i / 16;
	}
	return (c);
}
