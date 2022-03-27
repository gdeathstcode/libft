/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 07:30:08 by gdeathst          #+#    #+#             */
/*   Updated: 2022/03/03 07:30:10 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_ultoa(unsigned long value, char *buffer, int radix)
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
