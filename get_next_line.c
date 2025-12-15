/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 01:16:42 by vmistry           #+#    #+#             */
/*   Updated: 2025/12/15 19:27:08 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d > s)
		while (len-- > 0)
			d[len] = s[len];
	else
		while (len--)
			*d++ = *s++;
	return (dst);
}

static char	*extract_line(char *buffer, char *line)
{
	char	*nl;
	char	*tmp;
	char	*remainder;
	size_t	nl_index;

	nl = ft_strchr(buffer, '\n');
	nl_index = nl - buffer;
	remainder = ft_substr(buffer, 0, nl_index + 1);
	tmp = ft_strjoin(line, remainder);
	free(remainder);
	ft_memmove(buffer, nl + 1, ft_strlen(nl + 1) + 1);
	return (tmp);
}

static ssize_t	read_into_buffer(int fd, char *buffer, char **line)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	buffer[bytes_read] = '\0';
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	ssize_t		bytes_read;
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (ft_strchr(buffer, '\n') != NULL)
			return (extract_line(buffer, line));
		bytes_read = read_into_buffer(fd, buffer, &line);
		if (bytes_read < 0)
			return (NULL);
		if (bytes_read == 0)
			return (line);
		buffer[bytes_read] = '\0';
		if (ft_strchr(buffer, '\n') != NULL)
            		return (extract_line(buffer, line));
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
	}
}
