/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:52:01 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/27 09:45:50 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int ft_path_error (t_pipex *pipex)
{
    pipex->path = NULL;
    return (ft_putstr_fd("\nError no such file or directory", 1),-1);
}
  