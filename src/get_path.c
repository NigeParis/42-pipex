/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:01:13 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/24 10:08:19 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_get_line_nb(char pathname[], char *env[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!pathname || !env)
		return (-1);
	while (env && env[i])
	{
		while (env[i][j] == pathname[j] && j < 6)
		{
			j++;
		}
		if (j == 5 && j == (int)ft_strlen(pathname))
			return (i);
		j = 0;
		i++;
	}
	return (i);
}

char	**ft_get_paths(char *paths)
{
	char	**tab;

	tab = ft_split(&paths[5], ':');
	return (tab);
}


int	ft_path(t_pipex *pipex, char *cmd, char **env)
{
	int	i;

	i = 0;
	while (ft_strncmp(env[i], "PATH", 4) != 0)
		i++;
	pipex->paths = ft_split(env[i] + 5, ':');
	ft_cleanup_helper(pipex, 1);
	i = 0;
	pipex->valid_cmd = 1;
	while (pipex->paths && pipex->paths[i])
	{
		pipex->path_cmd = ft_strjoin(pipex->paths[i], "/");
		ft_cleanup_helper(pipex, 1);
		pipex->path = ft_strjoin(pipex->path_cmd, cmd);
		ft_cleanup_helper(pipex, 3);
		if (access(pipex->path, F_OK | R_OK) == 0)
		{
			pipex->valid_cmd = 0;
			pipex->all_cmd_valid++;
			ft_cleanup(pipex, 7);
			return (0);
		}
		i++;
	}
	ft_cleanup(pipex, 7);
	return (i);
}
