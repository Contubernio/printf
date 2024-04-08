/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_pf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:20:50 by albealva          #+#    #+#             */
/*   Updated: 2024/03/20 16:25:32 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putcharold(const char c)
{
	write (1, &c, 1);
	return (1);
}

size_t ft_putchar(const char c)
{
    ssize_t result;

    result = write(1, &c, 1);
    if (result == -1)
    {
        return (-1);
    }
    return (1);
}

size_t	ft_putstrold(const char *str)
{
	size_t	i;

	if (!str)
		return (ft_putstr("(null)"));
	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		++i;
	}
	return (i);
}

size_t ft_putstr(const char *str)
{
    size_t i;

    if (!str)
        return (ft_putstr("(null)"));
    i = 0;
    while (str[i])
    {
        if (write(1, &str[i], 1) == -1)
        {
            return (-1); 
        }
        ++i;
    }
    return (i);
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
