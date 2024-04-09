/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:58:40 by albealva          #+#    #+#             */
/*   Updated: 2024/04/08 19:03:17 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);

int	ft_printchar(char c, int *i);
int	ft_printstr(char *str, int *i);

int	ft_print_di(int n, int *i);
int	ft_read_base(unsigned int n, int *i, int c, unsigned int base_n);
int	ft_memaddrs(unsigned long n, int *i);

#endif