/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:20:32 by vmistry           #+#    #+#             */
/*   Updated: 2026/01/07 12:04:27 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// utils functions
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

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*joined_str;
// 	size_t	len_s1;
// 	size_t	i;

// 	if (!s1 && !s2)
// 		return (NULL);
// 	if (!s1)
// 		s1 = "";
// 	if (!s2)
// 		s2 = "";
// 	len_s1 = ft_strlen(s1);
// 	joined_str = (char *)malloc(len_s1 + ft_strlen(s2) + 1);
// 	if (!joined_str)
// 		return (NULL);
// 	i = 0;
// 	while (i < len_s1 + ft_strlen(s2))
// 	{
// 		if (s1[i])
// 			joined_str[i] = s1[i];
// 		if (s2[i - len_s1] && i >= len_s1)
// 			joined_str[i] = s2[i - len_s1];
// 		i++;
// 	}
// 	joined_str[i] = '\0';
// 	return (joined_str);
// }
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	res = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strdup(const char *s)
{
	char	*s2;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s) + 1;
	s2 = malloc(len);
	if (!s2)
		return (NULL);
	while (s[i])
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return ((char *)(s2));
}
