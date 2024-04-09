/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_cs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:58:31 by albealva          #+#    #+#             */
/*   Updated: 2024/04/08 19:01:24 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c, int *i)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	*i = (*i + 1);
	return (*i);
}

int	ft_printstr(char *str, int *i)
{
	int	j;

	j = 0;
	if (!str)
		str = "(null)";
	while (str[j])
	{
		if (ft_printchar(str[j], i) == -1)
			return (-1);
		j++;
	}
	return (*i);
}
