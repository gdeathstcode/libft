/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 04:10:22 by gdeathst          #+#    #+#             */
/*   Updated: 2022/03/03 04:10:25 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_itoa(int value, char *buffer, int radix)
{
	char	*ptr;
	int		digit;

	ptr = buffer;
	if ((radix < 2) || (radix > 36))
	{
		*ptr = '\0';
		return (buffer);
	}
	if (value == 0)
		*ptr++ = 0;
	while (value)
	{
		digit = value % radix;
		if (digit < 0xA)
			*ptr = '0' + digit;
		else
			*ptr = 'a' + digit - 0xA;
		ptr++;
		value = value / radix;
	}
	*ptr = '\0';
	ft_strrev(buffer);
	return (buffer);
}
