/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 16:37:28 by galves-d          #+#    #+#             */
/*   Updated: 2020/03/13 17:12:25 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef EOF
#  define EOF -1
# endif

# define BUFFER_SIZE 42

int			get_next_line(int fd, char **line);

ssize_t		find_char(const char *str, int c);
size_t		ft_strlen(const char *str);
void		ft_free(void **ptr);
void		*ft_memmove(void *dst, const void *src, size_t len);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif
