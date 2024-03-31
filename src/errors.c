/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:52:01 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/31 20:21:20 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"


int	ft_path_error(t_pipex *pipex)
{
    ft_printf("\n-----path_error--%s\n", pipex->path);
	ft_putstr_fd("\nError command not found", 1);
	return (1);
}

