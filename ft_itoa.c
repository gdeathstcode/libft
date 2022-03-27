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

#include "libft.h"

void	*ft_itoa(int value, char *buffer, int radix)
{
	char	*ptr;
	char	*digits;

	digits = "0123456789abcdefghijklmnopqrstuvwxyz";
	ptr = buffer;
	if ((radix < 2) || (radix > 36))
	{
		*buffer = '\0';
		return (buffer);
	}
	while (value / radix != 0)
	{
		*ptr++ = digits[ft_abs(value % radix)];
		value = value / radix;
	}
	*ptr++ = digits[ft_abs(value % radix)];
	if (value < 0 && radix == 10)
		*ptr++ = '-';
	*ptr = '\0';
	ft_strrev(buffer);
	return (buffer);
}
