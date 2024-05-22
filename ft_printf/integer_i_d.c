/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_i_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:08:16 by sgalli            #+#    #+#             */
/*   Updated: 2022/11/11 16:13:47 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	result(long int i);

int	integer_i_d(long int i)
{
	int	t;

	result(i);
	t = 0;
	if (i == 0)
	{
		t = 1;
		return (t);
	}
	if (i < 0)
	{
		t++;
		i = -i;
	}
	while (i != 0)
	{
		i = i / 10;
		t++;
	}
	return (t);
}

static int	result(long int i)
{
	if (i > 9)
	{
		result(i / 10);
		result(i % 10);
	}
	else if (i < 0)
	{
		character_c('-');
		i = -i;
		result(i);
	}
	else
	{
		character_c(i + '0');
	}
	return (i);
}
