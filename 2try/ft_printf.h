/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:16:52 by albealva          #+#    #+#             */
/*   Updated: 2024/03/20 16:03:34 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <sys/types.h>

int		ft_printf(const char *str, ...);
size_t	ft_putnbr_base(ssize_t nbr, char *base, size_t len, char spf);
size_t	ft_putstr(const char *str);
size_t	ft_putchar(const char c);
char	*ft_strchr(const char *s, int c);

#endif  