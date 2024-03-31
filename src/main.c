/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:45:37 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/31 22:30:19 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_cleanup(t_pipex *pipex)
{
	if (pipex->cmds)
		ft_free_double_tab(pipex->cmds);
	if (pipex->paths)
		ft_free_double_tab(pipex->paths);
	if (pipex->path)
		ft_free_tab(pipex->path);
	if (pipex->path_cmd)
		ft_free_tab(pipex->path_cmd);
//	close(pipex->fdin);
//	close(pipex->fdout);
//	if (pipex->fdin != -1)
//	close(pipex->pipe_fd[0]);
//	close(pipex->pipe_fd[1]);
}

int	open_in_out_files(t_pipex *pipex, int argc, char *argv[], int type)
{
	if (type == 1)
	{
		printf("\n----%s----argv2\n", argv[1]);
		pipex->fdin = open(argv[1], O_RDONLY, 0666);
		if (pipex->fdin == -1)
		{
			close(pipex->fdin);
			return (ft_putstr_fd("\nNo such files or directory\n", 1), 1);
		}
	}
	if (type == 0)
	{
		unlink(argv[argc - 1]);
		pipex->fdout = open(argv[argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	}
	return (0);
}

int	ft_clean_endfile(t_pipex *pipex, int argc, char *argv[], int type)
{
	open_in_out_files(pipex, argc, argv, type);
	return (0);
}

int  make_pipe(t_pipex *pipex, char *env[], int i, int argc)
{
 	pid_t process;

	printf("-%d- -argc%d- -%s-\n", i, argc, env[i]);
	pipe(pipex->pipe_fd);
  	process = fork();
 	if (!process)
 	{		
		close(pipex->pipe_fd[0]);
		dup2(pipex->pipe_fd[1],1);
		exec_cmd(pipex, env);  
		
 	}
  	else
  	{
		close(pipex->pipe_fd[1]);
		dup2(pipex->pipe_fd[0],0);   
 	}
  	return (0);
}

int main(int argc, char *argv[], char *env[])
{
	t_pipex pipex;
	pid_t   process;
	int     i;
  
	i = 2;
   	pipex.path = 0;  
   	pipex.paths = 0;
  	pipex.path_cmd = 0;
	pipex.cmds = 0;
  
	if (argc < 5)
		return (-1);
	ft_clean_endfile(&pipex, argc, argv, 0);
	if (open_in_out_files(&pipex, argc, argv, 1) == -1)
		return (-1);
  	while (i < argc - 2)
  	{
		if (i == 2)
			dup2(pipex.fdin, 0);
		get_cmd(&pipex, argv[i]);
	  	ft_path(&pipex, &pipex.cmds[0], env);
		if (pipex.path != NULL)
		{
		  	make_pipe(&pipex, env, i, argc);
		}
	  	i++;
  	}
	process = fork();

  	if (!process)
  	{
		get_cmd(&pipex, argv[i]);
		ft_path(&pipex, &pipex.cmds[0], env);
		printf("\n-----main------%s------->HERE\n", pipex.path);
		dup2(pipex.fdout, 1);
		exec_cmd(&pipex, env);
  	}
	wait(NULL);	
	if (process)
	{
		ft_cleanup(&pipex);
	}
  	
	return (0);
}
