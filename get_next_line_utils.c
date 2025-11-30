/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:20:32 by vmistry           #+#    #+#             */
/*   Updated: 2025/11/29 16:35:19 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	*arr;
	size_t	n;
	size_t	i;

	if (!size || !nitems)
		return (malloc(0));
	if (nitems > (size_t) - 1 / size)
		return (NULL);
	arr = malloc(nitems * size);
	if (!arr)
		return (NULL);
	n = nitems * size;
	i = 0;
	while (i < n)
		arr[i++] = 0;
	return (arr);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = 0;
	ch = (char) c;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i++;
	}
	if (!ch && s[i] == '\0')
		return ((char *)s + i);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*to;
	unsigned char	*from;
	size_t			i;

	if (!dst && !src)
		return (dst);
	to = (unsigned char *) dst;
	from = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		to[i] = from[i];
		i++;
	}
	return (to);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	joined_str = (char *)malloc(len_s1 + len_s2 + 1);
	if (!joined_str)
		return (NULL);
	ft_memcpy(joined_str, s1, len_s1);
	ft_memcpy(joined_str + len_s1, s2, len_s2);
	joined_str[len_s1 + len_s2] = '\0';
	return (joined_str);
}