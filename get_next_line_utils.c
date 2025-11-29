/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:20:32 by vmistry           #+#    #+#             */
/*   Updated: 2025/11/29 14:57:08 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	*arr;

	if (!size || !nitems)
		return (malloc(0));
	if (nitems > (size_t) - 1 / size)
		return (NULL);
	arr = malloc(nitems * size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, (nitems * size));
	return (arr);
}

void	ft_puts(char *s, int fd)
{
	size_t	len;

	if (!s)
		return ;
	len = 0;
	while (s[len])
		len++;
	write(fd, s, len);
}
