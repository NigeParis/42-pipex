/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:05:27 by nrobinso          #+#    #+#             */
/*   Updated: 2024/04/06 12:35:53 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printf_str_fd(int fd, char *s)
{
	size_t	count;

	count = 0;
	if (!s)
	{
		write(fd, "", 1);
		return (count);
	}
	else
	{
		count = ft_printf_strlen(s);
		write(fd, s, count);
	}
	return (count);
}
