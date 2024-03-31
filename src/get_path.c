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
	char	*line;
	char	**tab;
	int		i;
	int		j;

	i = 5;
	j = 0;
	if (!paths)
		return (NULL);
	line = ft_strdup(paths);
	//printf("\n\nline----->%s\n\n",line);
	if (!line)
		return (NULL);
	while (paths && paths[i])
	{
		line[j] = paths[i];
		j++;
		i++;
	}
	line[j] = ':';
	line[j + 1] = '\0';
	tab = ft_split(line, ':');
	//printf("\n\npath[0] = %s\n\n", tab[0]);
	ft_free_tab(line);
	return (tab);
}

int	ft_path(t_pipex *pipex, char **cmd, char **env)
{
	int	i;


	i = 0;
	pipex->path_nb = ft_get_line_nb("PATH=", env);
	pipex->paths = ft_get_paths(env[pipex->path_nb]);
	if (pipex->paths[i] == NULL)
		return (ft_path_error(pipex));


	pipex->path_cmd = ft_strjoin(pipex->paths[0], "/");
	pipex->path = ft_strjoin(pipex->path_cmd, cmd[0]);
	while (access(pipex->path, F_OK | R_OK) != 0)
	{
		ft_free_tab(pipex->path);
		ft_free_tab(pipex->path_cmd);
		i++;
		pipex->path_cmd = ft_strjoin(pipex->paths[i], "/");
		pipex->path = ft_strjoin(pipex->path_cmd, cmd[0]);
		//printf("\n\npipex->path -> %s\n\n", pipex->path);
		if (pipex->paths[i] == NULL)
		{
			ft_path_error(pipex);
//			ft_cleanup(pipex);
			return (0);
		}
		if (i == 0)		
			return (0);

	}
	return (i);
}
