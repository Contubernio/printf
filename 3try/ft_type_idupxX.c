/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_idupxX.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:58:14 by albealva          #+#    #+#             */
/*   Updated: 2024/04/09 19:24:46 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_di(int n, int *i)
{
	if (n == -2147483647)
	{
		if (type_s("-2147483647", i) == -1)
			return (-1);
	}
	else
	{
		if (n < 0)
		{
			if (type_c('-', i) == -1)
				return (-1);
			n *= -1;
		}
		if (type_u_xlow_xup(n, i, 0, 10) == -1)
			return (-1);
	}
	return (*i);
}

int	type_u_xlow_xup(unsigned int n, int *i, int opt, unsigned int bas)
{
	char	*base;

	if (opt == 0)
		base = "0123456789";
	if (opt == 1)
		base = "0123456789abcdef";
	if (opt == 2)
		base = "0123456789ABCDEF";
	if (n >= bas)
	{
		if (type_u_xlow_xup(n / bas, i, opt, bas) == -1)
			return (-1);
	}
	if (type_c(base[n % bas], i) == -1)
		return (-1);
	return (*i);
}

static int	putptr(unsigned long n, int *i)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		if (putptr(n / 16, i) == -1)
			return (-1);
	}
	if (type_c(base[n % 16], i) == -1)
		return (-1);
	return (*i);
}

int	type_p(unsigned long n, int *i)
{
	if (type_s("0x", i) == -1)
		return (-1);
	if (putptr(n, i) == -1)
		return (-1);
	return (*i);
}
