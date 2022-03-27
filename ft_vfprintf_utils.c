/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:42:35 by gdeathst          #+#    #+#             */
/*   Updated: 2022/03/04 15:42:37 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*string_conversion(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	return (str);
}

static char	*pointer_conversion(va_list ap, char *buffer)
{
	ft_strlcpy(buffer, "0x", ft_strlen("0x") + 1);
	ft_ultoa(va_arg(ap, unsigned long), buffer + 2, 16);
	return (buffer);
}

static char	*hex_conversion(va_list ap, char *buffer)
{
	char	*str;

	str = buffer;
	ft_utoa(va_arg(ap, unsigned int), buffer, 16);
	while (*buffer)
	{
		*buffer = ft_toupper(*buffer);
		buffer++;
	}
	return (str);
}

static int	character_conversion(va_list ap, int fd)
{
	ft_putchar_fd(va_arg(ap, int), fd);
	return (1);
}

int	ft_vfprintf_conversion(const char type, va_list ap, int fd)
{
	char	buffer[BUFSIZ];
	char	*str;
	int		printed;

	str = buffer;
	if (type == 'c')
		return (character_conversion(ap, fd));
	else if (type == 's')
		str = string_conversion(ap);
	else if (type == 'p')
		str = pointer_conversion(ap, buffer);
	else if (type == 'd' || type == 'i')
		str = ft_itoa(va_arg(ap, int), buffer, 10);
	else if (type == 'u')
		str = ft_utoa(va_arg(ap, unsigned int), buffer, 10);
	else if (type == 'x')
		str = ft_utoa(va_arg(ap, unsigned int), buffer, 16);
	else if (type == 'X')
		str = hex_conversion(ap, buffer);
	else if (type == '%')
		str = "%";
	ft_putstr_fd(str, fd);
	printed = ft_strlen(str);
	return (printed);
}
