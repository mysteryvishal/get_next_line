/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:07:55 by vmistry           #+#    #+#             */
/*   Updated: 2025/11/29 22:07:19 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	fill_line_buffer(char *line, char *buffer)
{
	
}

char	*get_next_line(int fd)
{
	int	bytes_read;
	char	*line;
	static char	*buffer;

	// 1. define the line to be read.
	line = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!line)
		return (NULL);
	
	// 
	while (1)
	{
		// 2. read a segment of the line and null terminate it
		bytes_read = read(fd, buffer, (BUFFER_SIZE + 1));
		if (bytes_read <= 0)
		{
			free(line);
			return (NULL);
		}
		buffer[bytes_read] = '\0';

		// 3. 
		if (ft_strchr(buffer, '\n') != NULL)
		{
			set_line();
			break;	
		}
		else
			fill_line_buffer();
	}
	
	
	
	return (NULL);
}
