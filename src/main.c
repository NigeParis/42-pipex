/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:45:37 by nrobinso          #+#    #+#             */
/*   Updated: 2024/04/02 13:41:47 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_init(t_pipex *pipex, int argc, char *argv[])
{
 	pipex->path = 0;  
   	pipex->paths = 0;
  	pipex->path_cmd = 0;
	pipex->cmds = 0;
	pipex->valid_cmd = 0;
	pipex->all_cmd_valid = 0;
	pipex->nbr_cmds = (argc - 3);
	pipex->nb_argc = argc;
	pipex->parse_flag = 0;
	if (access(argv[1], F_OK | R_OK) == 0)
		pipex->fdin = open(argv[1], O_RDONLY, 0777);
	else if (access(argv[1], F_OK ) == -1)
	{
		ft_putstr_fd("pipex: no such file or directory: ", 2);
		ft_putstr_fd(argv[1], 2);
		exit (1);
	}
	else if (access(argv[1], R_OK ) == -1)
	{
		ft_putstr_fd("pipex: permission denied: ", 2);
		ft_putstr_fd(argv[1], 2);
		exit (1);
	}
	pipex->fdout = open(argv[argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
}

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
	if (argc < 5)
		return (-1);
	ft_init(&pipex, argc, argv);
  	while (i <= argc - 2)
  	{
		make_pipe(&pipex, env, argv, i);
	  	i++;
  	}
	while (wait(NULL) > 0) ;
	close(pipex.pipe_fd[0]);
	close(pipex.pipe_fd[1]);
	ft_cleanup(&pipex, 6);
	close_fd(&pipex, 10);
	return (0);
}
