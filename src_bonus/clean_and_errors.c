/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:52:01 by nrobinso          #+#    #+#             */
/*   Updated: 2024/04/06 12:59:32 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_cleanup_helper1(t_pipex *pipex, int type)
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

void	ft_cleanup_helper2(t_pipex *pipex, int type)
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
		if (pipex->path)
			ft_free_tab(pipex->path);
	}
	if (type == 7)
	{
		if (pipex->all_cmd_valid == pipex->nbr_cmds)
			ft_free_double_tab(pipex->paths);
	}
}

void	ft_cleanup(t_pipex *pipex, int type)
{
	ft_cleanup_helper1(pipex, type);
	ft_cleanup_helper2(pipex, type);
	if (type == 8)
	{
		if (pipex->cmds && pipex->uni_path_flag == 1)
			ft_free_double_tab(pipex->cmds);
		if (pipex->path)
			ft_free_tab(pipex->path);
	}
	if (type == 9)
	{
		if (pipex->path_cmd)
			ft_free_tab(pipex->path_cmd);
	}
}

void	close_fd(t_pipex *pipex, int type)
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

void	ft_exec_cmd_error(t_pipex *pipex, char *message)
{
	char	str[100];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (message && message[i])
	{
		str[i] = message[i];
		i++;
	}
	while (pipex->cmds[0] && pipex->cmds[0][j])
	{
		str[i] = pipex->cmds[0][j];
		j++;
		i++;
	}
	str[i] = '\n';
	i++;
	str[i] = '\0';
	ft_printf_fd(2, "%F", str);
	ft_cleanup(pipex, 5);
	close_fd(pipex, 10);
}
