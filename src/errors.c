/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:52:01 by nrobinso          #+#    #+#             */
/*   Updated: 2024/04/02 13:00:28 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"


int	ft_path_error(t_pipex *pipex)
{
    ft_printf("\n-----path_error--%s\n", pipex->path);
	ft_putstr_fd("\nError command not found", 1);
	return (1);
}

void	ft_cleanup(t_pipex *pipex, int type)
{
	if (type == 5)
	{
		if (pipex->cmds)
			ft_free_double_tab(pipex->cmds);
		if (pipex->paths)
			ft_free_double_tab(pipex->paths);
	}

	
	if (type == 6)
	{
		if (pipex->cmds)
			ft_free_double_tab(pipex->cmds);
		if (pipex->paths)
			ft_free_double_tab(pipex->paths);
		if (pipex->path)
			ft_free_tab(pipex->path);
		if (pipex->path_cmd)
			ft_free_tab(pipex->path_cmd);
	}
	if (type == 4)
	{
		if (pipex->cmds)
			ft_free_double_tab(pipex->cmds);
		if (pipex->paths)
			ft_free_double_tab(pipex->paths);
	}
	if (type == 2)
	{
		if (pipex->path)
			ft_free_tab(pipex->path);
		if (pipex->path_cmd)
			ft_free_tab(pipex->path_cmd);
	}
	if (type == 1)
	{
		if (pipex->path)
			ft_free_tab(pipex->path);
	}

}


void close_fd(t_pipex *pipex, int type)
{
	if (type == 0)
	{
		if (pipex->fdin)
			close (pipex->fdin);
	}
	if (type == 1)
	{
		if (pipex->fdout)
			close (pipex->fdout);
	}
	if (type == 10)
	{
		if (pipex->fdin && pipex->fdout)
		{
			close (pipex->fdout);
			close (pipex->fdin);
		}
	}

	
}


