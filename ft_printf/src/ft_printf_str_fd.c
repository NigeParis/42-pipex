/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:05:27 by nrobinso          #+#    #+#             */
/*   Updated: 2024/04/05 17:30:07 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printf_str_fd(char *s, int fd)
{
	size_t	count;

	count = 0;
	if (!s)
	{
		count = ft_printf_str_fd("(null)", fd);
		return (count);
	}
	while (*s)
	{
		count += ft_printf_char_fd(*s, fd);
		s++;
	}
	return (count);
}
