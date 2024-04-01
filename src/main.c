/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:45:37 by nrobinso          #+#    #+#             */
/*   Updated: 2024/04/01 22:17:50 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"



int  make_pipe(t_pipex *pipex, char *env[], char *argv[], int i)
{
 	pid_t process;

	pipe(pipex->pipe_fd);
  	process = fork();
 	if (!process)
 	{	
		close(pipex->pipe_fd[0]);
		if (i == 2)
			dup2(pipex->fdin, 0);
		if (i == pipex->nb_argc - 2)
			dup2(pipex->fdout, 1);
		else
		{
			dup2(pipex->pipe_fd[1],1);
			
		}
		close(pipex->pipe_fd[1]);
		exec_cmd(pipex, i, argv, env);
 	}
  	else
  	{
		close(pipex->pipe_fd[1]);
		dup2(pipex->pipe_fd[0],0);
		close(pipex->pipe_fd[0]);
 	
	}
	
  	return (0);
}

int main(int argc, char *argv[], char *env[])
{
	t_pipex pipex;
	int     i;
  
	i = 2;
   	pipex.path = 0;  
   	pipex.paths = 0;
  	pipex.path_cmd = 0;
	pipex.cmds = 0;
	pipex.valid_cmd = 0;
	pipex.all_cmd_valid = 0;
	pipex.nbr_cmds = (argc - 3);
	pipex.nb_argc = argc;
  
	if (argc < 5)
		return (-1);
	pipex.fdin = open(argv[1], O_RDONLY, 0777);
	pipex.fdout = open(argv[argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
  	while (i <= argc - 2)
  	{
		
		make_pipe(&pipex, env, argv, i);
		ft_free_double_tab(pipex.cmds);
	  	i++;
  	}
	while (wait(NULL) > 0) ;
	if (pipex.path && (pipex.all_cmd_valid == pipex.nbr_cmds))
		free(pipex.path);
	return (0);
}
