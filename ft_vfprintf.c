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
#include <stdbool.h>

static void ft_strtoupper(unsigned int i, char *str) {
	str[i] = ft_toupper(str[i]);
}

int ft_vfprintf(FILE *stream, const char *format, va_list ap)
{
	int		fd;
	bool	isEnd;
	int 	totalLenght;

	fd = stream->_file;
	totalLenght = 0;
	isEnd = (*format == '\0') ? true : false;
	while (!isEnd) {
		bool isConversion = (*format == '%') ? true : false;
		if (isConversion) {
			format++;
			char *str;
			char buf[36];
			switch (*format) {
				case 'c':
					ft_putchar_fd(va_arg(ap, int), fd);
					totalLenght++;
					break;
				case 's':
					str = va_arg(ap, char*);
                    if (str == NULL) {
                        str = buf;
                        ft_strlcpy(buf, "(null)", ft_strlen("(null)") + 1);
                    }
					ft_putstr_fd(str, fd);
					totalLenght = totalLenght + ft_strlen(str);
					break;
				case 'p':
                    ft_strlcpy(buf, "0x", ft_strlen("0x") + 1);
					ft_ultoa(va_arg(ap, unsigned long), buf + 2, 16);
                    str = buf;
					ft_putstr_fd(str, fd);
					totalLenght = totalLenght + ft_strlen(str);
					break;
				case 'd':
				case 'i':
					ft_itoa(va_arg(ap, int), buf, 10);
					ft_putstr_fd(buf, fd);
					totalLenght = totalLenght + ft_strlen(buf);
					break;
				case 'u':
					str = ft_utoa(va_arg(ap, unsigned int), buf, 10);
					ft_putstr_fd(str, fd);
					totalLenght = totalLenght + ft_strlen(str);
					break;
				case 'x':
					str = ft_utoa(va_arg(ap, unsigned int), buf, 16);
					ft_putstr_fd(str, fd);
					totalLenght = totalLenght + ft_strlen(str);
					break;
				case 'X':
					str = ft_utoa(va_arg(ap, unsigned int), buf, 16);
					ft_striteri(str, ft_strtoupper);
					ft_putstr_fd(str, fd);
					totalLenght = totalLenght + ft_strlen(str);
					break;
				case '%':
					ft_putchar_fd('%', fd);
					totalLenght++;
					break;
			}
			format++;
		}
		else {
			ft_putchar_fd(*format, fd);
			format++;
			totalLenght++;
		}
		isEnd = (*format == '\0') ? true : false;
	}
	return (totalLenght);
}
