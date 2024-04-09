/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_pf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:12:53 by albealva          #+#    #+#             */
/*   Updated: 2024/04/09 19:04:17 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(const char c, int *count)
{
	int	result;

	result = write(1, &c, 1);
	if (result != -1)
		count[0]++;
	else
		count[0] = -1;
	return ;
}

void	ft_putstr(const char *str, int *count)
{
	int	i;

	if (!str)
		return (ft_putstr("(null)", count));
	i = 0;
	while (str[i] && count[0] != -1)
	{
		ft_putchar(str[i], count);
		++i;
	}
	return ;
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		++i;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (0);
}
