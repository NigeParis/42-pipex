/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:45:37 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/27 23:58:30 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void  ft_cleanup(t_pipex *pipex)
{
    ft_free_double_tab(pipex->cmds);
    ft_free_double_tab(pipex->paths);
    ft_free_tab(pipex->path);
    ft_free_tab(pipex->path_cmd);
}



int  open_in_out_files(t_pipex *pipex, int argc, char *argv[], int type)
{
    if (type == 1)
    {
      pipex->fd = open(argv[1], O_RDONLY, 0777);
      if (pipex->fd == -1)
       return (ft_putstr_fd("\nNo such file or directory\n", 1), -1);
    }
    if (type == 0)
    {
      pipex->fd = open(argv[argc -1], O_WRONLY | O_CREAT, 0777);
      if (pipex->fd == -1)
       return (ft_putstr_fd("\nNo such file or directory\n", 1), -1);
    }
  return (0);
}

int	ft_clean_endfile(t_pipex *pipex, int argc, char *argv[], int type)
{
	int	fd;

	fd = open(argv[argc - 1], O_RDONLY);
	if (!fd || fd == -1)
	{
		ft_printf("Error\n%s making one\n", argv[argc]);
		close(fd);
    open_in_out_files(pipex, argc, argv, type);
		return (1);
	}
	close (fd);
  unlink(argv[argc - 1]);
  open_in_out_files(pipex, argc, argv, type);
	return (0);
}





int  make_pipe(t_pipex *pipex, char *env[])
{
  pid_t process;
  int   intwait;

  pipe(pipex->pipe_fd);
  process = fork();
  if (!process)
  {
    waitpid(process, &intwait, WUNTRACED);
    
    close(pipex->pipe_fd[0]);
    dup2(pipex->pipe_fd[1],1);
    exec_cmd(pipex, env);  
  }
  else
  {
    waitpid(process, &intwait, WUNTRACED);

    close(pipex->pipe_fd[1]);
    dup2(pipex->pipe_fd[0],0);   
  }
 

  return (0);
}

int main(int argc, char *argv[], char *env[])
{
  t_pipex pipex;
  int   i;
  
  i = 2;
  if (argc < 5)
    return (-1);
  ft_clean_endfile(&pipex, argc, argv, 0);
  if (open_in_out_files(&pipex, argc, argv, 1) == -1)
    return (-1);
  dup2(pipex.fd, 0);


  while (i < argc - 2)
  {
      get_cmd(&pipex, argv[i]);
      ft_path(&pipex, &pipex.cmds[0], env);
      make_pipe(&pipex, env);
      i++;
  }
  get_cmd(&pipex, argv[i]);
  ft_path(&pipex, &pipex.cmds[0], env);
  open_in_out_files(&pipex, argc, argv, 0);
  dup2(pipex.fd, 1);
  exec_cmd(&pipex, env);
      
  return (0);
}
