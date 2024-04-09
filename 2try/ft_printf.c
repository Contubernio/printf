/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:10:23 by albealva          #+#    #+#             */
/*   Updated: 2024/04/09 19:20:36 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_spf(const char c, va_list ap, int	*count)
{
	if (c == 'c')
		ft_putchar(va_arg(ap, int), count);
	else if (c == '%')
		ft_putchar('%', count);
	else if (c == 's')
		ft_putstr(va_arg(ap, char *), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr_base(va_arg(ap, int), DECIMAL, c, count);
	else if (c == 'u')
		ft_putnbr_base(va_arg(ap, unsigned), DECIMAL, c, count);
	else if (c == 'x')
		ft_putnbr_base(va_arg(ap, unsigned), LOWER_HEX, c, count);
	else if (c == 'X')
		ft_putnbr_base(va_arg(ap, unsigned), UPPER_HEX, c, count);
	else if (c == 'p')
	{
		if (count[0] < 0)
			return ;
		ft_putnbr_base(va_arg(ap, long), LOWER_HEX, c, count);
	}
	else
		count[0] = -1;
	return ;
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	va_start(ap, str);
	while (str[i] && count != -1)
	{
		if (str[i] == '%' && ft_strchr(SPF, str[i + 1]))
		{
			print_spf(str[i + 1], ap, &count);
			i++;
			if (count < 0)
				return (-1);
		}
		else
		{
			ft_putchar(str[i], &count);
			if (count < 0)
				return (-1);
		}
		i++;
	}
	va_end(ap);
	return (count);
}

/*
int	main(void)
{
	#include "ft_printf.h"
	#include <stdio.h>
    int num = -42;
    unsigned int u_num = 4294967295;
    char *str = "Ejemplo de cadena";
    char c = 'A';
    void *ptr = (void *)str;

    ft_printf("Prueba de caracter: %c\n", c);
    printf("Prueba original (printf): %c\n\n", c);

    ft_printf("Prueba de cadena: %s\n", str);
    printf("Prueba original (printf): %s\n\n", str);

    ft_printf("Prueba de numero decimal (int): %d\n", num);
    printf("Prueba original (printf): %d\n\n", num);

    ft_printf("Prueba de numero decimal sin signo (unsigned): %u\n", u_num);
    printf("Prueba original (printf): %u\n\n", u_num);

    ft_printf("Prueba de numero hexadecimal (minusculas): %x\n", u_num);
    printf("Prueba original (printf): %x\n\n", u_num);

    ft_printf("Prueba de numero hexadecimal (mayusculas): %X\n", u_num);
    printf("Prueba original (printf): %X\n\n", u_num);

    ft_printf("Prueba de puntero: %p\n", ptr);
    printf("Prueba original (printf): %p\n", ptr);

    return 0;
}*/