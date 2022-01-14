/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 06:47:43 by gdeathst          #+#    #+#             */
/*   Updated: 2021/12/26 06:47:44 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

//static int get(int fd, char *buf)
//{
//	int		bytes;
//
//	bytes = ft_strlen(buf);
//	if (*buf == '\0')
//	{
//		bytes = read(fd, buf, BUFFER_SIZE);
//		if (bytes != -1)
//			buf[bytes] = '\0';
//	}
//	return (bytes);
//}

//char	*get_next_line(int fd)
//{
//	static char	buf[BUFFER_SIZE + 1];
//	char 		*line;
//	char 		*line_break;
//	int			buf_len;
//	int			line_len;
//	int 		bytes;
//	char 		*tmp;
//
//	read(fd, buf);
//	line = NULL;
//	line_break = NULL;
//	while (*buf)
//	{
//		line_len = 0;
//		if (line)
//			line_len = ft_strlen(line);
//
//		line_break = ft_strchr(buf, '\n');
//		if (line_break)
//			buf_len = line_break - buf + 1;
//		else
//			buf_len = ft_strlen(buf);
//
//		tmp = line;
//		line = (char *)malloc(sizeof(char) * (buf_len + line_len + 1));
//		if (line == NULL)
//			return (NULL);
//		if (tmp)
//		{
//			ft_strlcpy(line, tmp, line_len + 1);
//			free(tmp);
//		}
//
//		ft_strlcpy(line + line_len, buf, buf_len + 1);
//
//		ft_strlcpy(buf, buf + buf_len, BUFFER_SIZE - buf_len + 1);
//		if (line_break)
//			break ;
//
//		if (read_(fd, buf) == -1)
//		{
//			free(line);
//			return (NULL);
//		}
//	}
//	return (line);
//}

char 	*get_next_line(int fd) {
	static char	buf[FILEDESCRIPTORS][BUFFER_SIZE];
	static char size[FILEDESCRIPTORS];
	char 		*line;
	char 		*line_break;
	int 		to_copy;
	char 		*tmp;
	int			line_size;

	if (size[fd] == 0)
		size[fd] = read(fd, buf[fd], BUFFER_SIZE);

	line_size = 0;
	line = NULL;

	while (size[fd] != 0) {


		if (size[fd] == -1) {
			free(line);
			break;
		}

		line_break = (char *)ft_memchr(buf[fd], '\n', size[fd]);
		to_copy = size[fd];
		if (line_break != NULL)
			to_copy = line_break - &buf[fd][0] + 1;

		tmp = line;
		line = (char *)malloc(sizeof(char) * (line_size + to_copy + 1));
		ft_memcpy(line, tmp, line_size);
		ft_memcpy(line + line_size, buf[fd], to_copy);
		line[to_copy + line_size] = '\0';
		line_size = to_copy + line_size;

		free(tmp);

		ft_memcpy(buf[fd], buf[fd] + to_copy, size[fd] - to_copy);
		size[fd] = size[fd] - to_copy;

		if (line_break)
			break ;

		if (size[fd] == 0)
			size[fd] = read(fd, buf[fd], BUFFER_SIZE);
	}
	return (line);
}
