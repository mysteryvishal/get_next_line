/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:17:09 by vmistry           #+#    #+#             */
/*   Updated: 2025/11/29 15:52:51 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define MAX_BUFFER 1024
# define BUFFER_SIZE 1

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

void	*ft_calloc(size_t nitems, size_t size);
void	ft_puts(char *s, int fd);

#endif