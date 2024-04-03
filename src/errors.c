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

void	ft_cleanup_helper(t_pipex *pipex, int type)
{
	if (type == 4)
	{
		if (pipex->cmds)
			ft_free_double_tab(pipex->cmds);
		if (pipex->paths)
			ft_free_double_tab(pipex->paths);
	}
	if (type == 3)
	{
		if (pipex->path_cmd)
			ft_free_tab(pipex->path_cmd);
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

void	ft_cleanup(t_pipex *pipex, int type)
{
	ft_cleanup_helper(pipex, type);
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
	if (type == 7)
	{
		if (pipex->all_cmd_valid == pipex->nbr_cmds)
			ft_free_double_tab(pipex->paths);
	}
}

void close_fd(t_pipex *pipex, int type)
{
	if (type == 0)
	{
		if (pipex->fdin != -1)
			close (pipex->fdin);
	}
	if (type == 1)
	{
		if (pipex->fdout != -1)
			close (pipex->fdout);
	}
	if (type == 10)
	{
		if (pipex->fdin != -1 && pipex->fdout != -1)
		{
			close (pipex->fdout);
			close (pipex->fdin);
		}
	}
}
