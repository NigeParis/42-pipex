/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:54:14 by nrobinso          #+#    #+#             */
/*   Updated: 2024/04/10 08:20:14 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	make_pipe(t_pipex *pipex, char *env[], char *argv[], int i)
{
	pid_t	process;
	int		ret;

	ret = pipe(pipex->pipe_fd);
	if (ret < 0)
		perror("pipe");
	process = fork();
	if (process == -1)
		perror("fork");
	if (!process)
	{
		child_process(pipex, argv, env, i);
	}
	else
	{
		parent_process(pipex);
	}
	return (0);
}

void	child_process(t_pipex *pipex, char *argv[], char *env[], int i)
{
	close(pipex->pipe_fd[0]);
	if (i == 2)
		dup2(pipex->fdin, STDIN_FILENO);
	if (i == pipex->nb_argc - 2)
	{
		dup2(pipex->fdout, STDOUT_FILENO);
		close_fd(pipex, 1);
	}
	else
	{
		dup2(pipex->pipe_fd[1], STDOUT_FILENO);
		close(pipex->pipe_fd[0]);
	}
	close_fd(pipex, 10);
	close(pipex->pipe_fd[1]);
	get_path_absolu(pipex, argv, i);
	exec_cmd(pipex, i, argv, env);
}

void	parent_process(t_pipex *pipex)
{
	close(pipex->pipe_fd[1]);
	dup2(pipex->pipe_fd[0], STDIN_FILENO);
	close(pipex->pipe_fd[1]);
}
