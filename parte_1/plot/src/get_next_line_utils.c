/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 17:23:18 by galves-d          #+#    #+#             */
/*   Updated: 2020/03/13 17:12:58 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

ssize_t	find_char(const char *str, int c)
{
	ssize_t	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (str && str[i] == c)
		return (i);
	return (-1);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

void	ft_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (src && len && (unsigned long)dst > (unsigned long)src)
	{
		i = 1;
		while (src != dst && i <= len)
		{
			*(unsigned char*)(dst + len - i) = *(unsigned char*)(src + len - i);
			i++;
		}
	}
	else if (src && len)
	{
		i = 0;
		while (dst != src && i < len)
		{
			*(unsigned char*)(dst + i) = *(unsigned char*)(src + i);
			i++;
		}
	}
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		length;
	size_t		s_len;
	char		*sub;

	length = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s + start);
	if (start < ft_strlen(s))
		length = (len > s_len ? s_len : len);
	if (!(sub = (char*)malloc((length + 1) * sizeof(char))))
		return (NULL);
	ft_memmove(sub, &s[start], length * sizeof(char));
	sub[length] = '\0';
	return (sub);
}
