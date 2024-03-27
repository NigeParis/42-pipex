/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:25:41 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/27 08:24:54 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
size_t	ft_gnl_strlen(char *str);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_gnl_strdup(char *s1);
size_t	ft_gnl_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_gnl_strchr(char *s, int c);
#endif
