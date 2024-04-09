/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:58:09 by albealva          #+#    #+#             */
/*   Updated: 2024/04/09 19:24:41 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

// =========================== CHAR AND STR ================================= //

int	type_c(char c, int *i);
int	type_s(char *c, int *i);

// =========================== PTRS AND NUM ================================= //

int	type_di(int n, int *i);
int	type_p(unsigned long n, int *i);
int	type_u_xlow_xup(unsigned int n, int *i, int opt, unsigned int bas);

// =========================== MAIN FUNTIONS ================================ //
int	ft_printf(char const *str, ...);

#endif
