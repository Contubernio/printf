/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:20:14 by albealva          #+#    #+#             */
/*   Updated: 2024/04/09 18:54:35 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_base(ssize_t num, char *base, size_t base_len, int *count)
{
	char	str[20];
	size_t	rem;
	size_t	i;

	i = 0;
	if (num == 0)
		ft_putchar(base[0], count);
	while (num != 0)
	{
		rem = num % base_len;
		str[i] = base[rem];
		num /= base_len;
		++i;
	}
	while (i--)
		ft_putchar(str[i], count);
	return ;
}

void	ft_putnbr_base(ssize_t nbr, char *base, char spf, int *count)
{
	int	i;

	i = 0;
	while (base[i] != 0)
		i++;
	if ((spf == 'd' || spf == 'i' || spf == 'u') && nbr < 0)
	{
		ft_putchar('-', count);
		nbr = -nbr;
	}
	else if (spf == 'p' && nbr == 0)
	{
		ft_putstr("0x0", count);
		return ;
	}
	else if (spf == 'p')
		ft_putstr("0x", count);
	print_base(nbr, base, i, count);
	return ;
}
