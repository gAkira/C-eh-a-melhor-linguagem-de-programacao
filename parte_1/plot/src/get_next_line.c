/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 16:50:31 by galves-d          #+#    #+#             */
/*   Updated: 2020/03/12 21:31:54 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

static int	put_line_file(char **line, char **file, size_t endl)
{
	int		rtrn_value;
	char	*aux;

	if ((*file)[0] == EOF)
	{
		ft_free((void**)file);
		if (!(*line = (char*)malloc(1)))
			return (-1);
		(*line)[0] = '\0';
		return (0);
	}
	rtrn_value = 1;
	if (find_char(*file, '\n') < 0 && find_char(*file, EOF) >= 0)
		rtrn_value = 0;
	if (!(*line = ft_substr(*file, 0, endl)) || !(aux = ft_substr(*file,
					endl + 1, ft_strlen(*file) - endl - 1)))
		return (-1);
	ft_free((void**)file);
	*file = aux;
	return (rtrn_value);
}

static int	put_line(char **line, char **file, char **buf, size_t endl)
{
	int		rtrn_value;
	size_t	file_len;
	size_t	buf_len;

	rtrn_value = 1;
	if ((*buf)[endl] == EOF)
		rtrn_value = 0;
	file_len = ft_strlen(*file);
	buf_len = rtrn_value ? endl : endl + 1;
	if (!(*line = (char*)malloc(file_len + endl + 1)))
	{
		ft_free((void**)buf);
		return (-1);
	}
	ft_memmove(*line, *file, file_len);
	ft_memmove(&((*line)[file_len]), *buf, endl);
	(*line)[file_len + endl] = '\0';
	ft_free((void**)file);
	if (buf_len < ft_strlen(*buf))
		*file = ft_substr(*buf, buf_len + 1, ft_strlen(*buf) - buf_len - 1);
	ft_free((void**)buf);
	return (rtrn_value);
}

static int	store_file_buf(char **file, char **buf)
{
	char	*aux;
	size_t	file_len;
	size_t	buf_len;

	file_len = ft_strlen(*file);
	buf_len = ft_strlen(*buf);
	if (!(aux = (char*)malloc(file_len + buf_len + 1)))
	{
		ft_free((void**)buf);
		return (0);
	}
	ft_memmove(aux, *file, file_len);
	ft_memmove(&(aux[file_len]), *buf, buf_len + 1);
	ft_free((void**)file);
	ft_free((void**)buf);
	*file = aux;
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char		*files[5];
	char			*buf;
	ssize_t			endl;
	ssize_t			buf_size;

	buf = NULL;
	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	if (files[fd] && ((endl = find_char(files[fd], '\n')) >= 0 ||
				(endl = find_char(files[fd], EOF)) >= 0))
		return (put_line_file(line, &files[fd], (size_t)endl));
	if (!(buf = malloc(BUFFER_SIZE + 2)) ||
			(buf_size = read(fd, buf, BUFFER_SIZE)) < 0)
		return (-1);
	buf[buf_size] = buf_size < BUFFER_SIZE ? EOF : '\0';
	buf[buf_size + 1] = '\0';
	if (((endl = find_char(buf, '\n')) >= 0 ||
				(endl = find_char(buf, EOF)) >= 0))
		return (put_line(line, &files[fd], &buf, (size_t)endl));
	if ((endl = find_char(buf, '\n')) < 0 && (endl = find_char(buf, EOF)) < 0)
		if (!store_file_buf(&files[fd], &buf))
			return (-1);
	return (get_next_line(fd, line));
}
