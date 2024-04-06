/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:54:14 by nrobinso          #+#    #+#             */
/*   Updated: 2024/04/06 11:55:09 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"


void	child_process(t_pipex *pipex, char *argv[], char *env[], int i)
{
	close(pipex->pipe_fd[0]);
	if (i == 2)
		dup2(pipex->fdin, 0);
	if (i == pipex->nb_argc - 2)
	{
		dup2(pipex->fdout, 1);
		close_fd(pipex, 1);
	}		
	else
	{
		dup2(pipex->pipe_fd[1],1);
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
	dup2(pipex->pipe_fd[0],0);
	close(pipex->pipe_fd[1]);
}

int  make_pipe(t_pipex *pipex, char *env[], char *argv[], int i)
{
 	pid_t process;

	pipe(pipex->pipe_fd);
	if (pipe < 0)
		perror("pipe");
  	process = fork();
	if (process == -1)
		perror("fork");
 	if (!process)
 	{
		child_process(pipex, argv, env, i);	;
 	}
  	else
  	{
		parent_process(pipex);
	}
  	return (0);
}