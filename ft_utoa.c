/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 04:20:18 by gdeathst          #+#    #+#             */
/*   Updated: 2022/03/03 04:20:19 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_utoa(unsigned int value, char *buffer, int radix)
{
	const char		*digits;
	unsigned int	remainder;
	char			*ptr;

	digits = "0123456789abcdefghijklmnopqrstuvwxyz";
	ptr = buffer;
	if ((radix < 2) || (radix > 36))
	{
		*buffer = '\0';
		return (buffer);
	}
	if (value == 0)
		*ptr++ = '0';
	while (value != 0)
	{
		remainder = value % radix;
		*ptr++ = digits[remainder];
		value = value / radix;
	}
	*ptr = '\0';
	ft_strrev(buffer);
	return (buffer);
}
