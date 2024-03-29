/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:29:28 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/29 15:19:52 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	clean_cmd_path(t_pipex	*pipex)
{
	int	flag;
	int	i;
	int	j;

	flag = 0;
	i = 0;
	j = 0;
	while (pipex->cmds[0] && pipex->cmds[0][i])
	{
		if (pipex->cmds[0][i] == '/')
		flag++;
		i++;
	}
	if (!flag)
		return ;
	while (pipex->cmds[0][i] != '/')
		i--;
	i++;
	while (pipex->cmds[0][i])
	{
		pipex->cmds[0][j++] = pipex->cmds[0][i++];
	}
	pipex->cmds[0][j] = '\0';
}

int	get_cmd(t_pipex *pipex, char *argv)
{
	char	*tmp;

	tmp = ft_strdup(argv);
	pipex->cmds = ft_split(tmp, ' ');
	free(tmp);
	if ((access(pipex->cmds[0], F_OK | R_OK)) == 0)
		clean_cmd_path(pipex);
	return (0);
}

void	exec_cmd(t_pipex *pipex, char *env[])
{
	int	ret;

	ret = execve(pipex->path, &pipex->cmds[0], env);
	if (ret == -1)
	{
		ft_cleanup(pipex);
		exit (1);
	}
}
