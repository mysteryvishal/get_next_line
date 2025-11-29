/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:17:09 by vmistry           #+#    #+#             */
/*   Updated: 2025/11/16 11:22:12 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define MAX_BUFFER 1024

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
// helper functions
void	*ft_calloc(size_t nitems, size_t size);

#endif