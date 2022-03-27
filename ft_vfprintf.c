/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:12:06 by gdeathst          #+#    #+#             */
/*   Updated: 2022/03/03 22:12:08 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vfprintf(FILE *stream, const char *format, va_list ap)
{
	int		fd;
	int		printed;

	fd = stream->_file;
	printed = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			printed = printed + ft_vfprintf_conversion(*format, ap, fd);
		}
		else
		{
			ft_putchar_fd(*format, fd);
			printed++;
		}
		format++;
	}
	return (printed);
}
