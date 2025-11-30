/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:07:55 by vmistry           #+#    #+#             */
/*   Updated: 2025/11/30 13:17:06 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	int	bytes_read;
	char	*line;
	static char	*buffer;

	// 1 >> define the line to be read.
	line = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!line)
		return (NULL);

	// 2 >> add any remaining bytes from previous operation to line
	ft_strjoin(line, ft_strchr(buffer, '\n'));

	// 3 >> loop until a new line is found
	while (1)
	{
		// 3.1 >> read a segment of the line and null terminate it
		bytes_read = read(fd, buffer, (BUFFER_SIZE + 1));
		if (bytes_read <= 0)
		{
			free(line);
			return (NULL);
		}
		buffer[bytes_read] = '\0';

		// 3.2 >> check if there's a newline in buffer
		if (ft_strchr(buffer, '\n') != NULL)
		{
			// char *temp;
			// ft_memcpy(temp, buffer, ft_strchr(buffer, '\n'));
			ft_strjoin(line, ft_substr(buffer, ft_strchr(buffer, '\n'), BUFFER_SIZE));
			break;
		}
		else
			ft_strjoin(line, buffer);
	}
	return (line);
}
