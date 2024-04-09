/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_cs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:58:05 by albealva          #+#    #+#             */
/*   Updated: 2024/04/09 19:24:44 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_c(char c, int *i)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	*i = (*i + 1);
	return (*i);
}

int	type_s(char *c, int *i)
{
	int	j;

	j = 0;
	if (!c)
		c = "(null)";
	while (c[j] != '\0')
	{
		if (type_c(c[j], i) == -1)
			return (-1);
		j++;
	}
	return (*i);
}
