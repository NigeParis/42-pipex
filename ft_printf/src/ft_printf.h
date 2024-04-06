/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 07:43:04 by nrobinso          #+#    #+#             */
/*   Updated: 2024/04/06 12:34:48 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_formatcheck(va_list input, char c);
int		ft_printf_unsigned_nbr(unsigned int nb);
int		ft_printf_nbr(int nb);
size_t	ft_printf_str(char *s);
int		ft_len_of_nbr(unsigned int nb);
size_t	ft_printf_hex(int flag, unsigned int nbr, char *base);
size_t	ft_printf_ptr(int flag, size_t nbr, char *base);
size_t	ft_printf_char(char c);
int		ft_printf_fd(int fd, const char *str, ...);
size_t	ft_printf_char_fd(char c, int fd);
size_t	ft_printf_str_fd(int fd, char *s);
size_t	ft_printf_strlen(const char *s);
int		ft_formatchk_fd(int fd, va_list input, char c);

#endif
