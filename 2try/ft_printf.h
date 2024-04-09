/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:16:52 by albealva          #+#    #+#             */
/*   Updated: 2024/04/09 18:41:45 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <sys/types.h>

# define LOWER_HEX "0123456789abcdef"
# define UPPER_HEX "0123456789ABCDEF"
# define SPF	"cspdiuxX%"
# define DECIMAL "0123456789"

int			ft_printf(const char *str, ...);
void		ft_putnbr_base(ssize_t nbr, char *base, char spf, int *count);
void		ft_putstr(const char *str, int *count);
void		ft_putchar(const char c, int *count);
char		*ft_strchr(const char *s, int c);

#endif  
