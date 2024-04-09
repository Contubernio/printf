/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:17:52 by albealva          #+#    #+#             */
/*   Updated: 2024/04/09 10:16:57 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_spf(const char c, va_list ap)
{
	size_t	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (c == '%')
		count += ft_putchar('%');
	else if (c == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr_base(va_arg(ap, int), DECIMAL, 10, c);
	else if (c == 'u')
		count += ft_putnbr_base(va_arg(ap, unsigned), DECIMAL, 10, c);
	else if (c == 'x')
		count += ft_putnbr_base(va_arg(ap, unsigned), LOWER_HEX, 16, c);
	else if (c == 'X')
		count += ft_putnbr_base(va_arg(ap, unsigned), UPPER_HEX, 16, c);
	else if (c == 'p')
		count += ft_putnbr_base(va_arg(ap, long), LOWER_HEX, 16, c);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr(SPF, str[i + 1]))
		{
			count += print_spf(str[i + 1], ap);
			i++;
		}
		else
		{
			count += ft_putchar(str[i]);
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
}
*/
