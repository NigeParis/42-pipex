/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:45:37 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/27 14:45:03 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void  ft_cleanup(t_pipex *pipex)
{
    ft_free_double_tab(pipex->cmds);
    ft_free_double_tab(pipex->paths);
    ft_free_tab(pipex->path);
    ft_free_tab(pipex->path_cmd);
}

int  open_in_out_files(t_pipex *pipex, char *argv[], int type)
{
    if (type == 1)
    {
      pipex->fd = open(argv[1], O_RDONLY, 0777);
      if (pipex->fd == -1)
       return (ft_putstr_fd("\nNo such file or directory", 1), -1);
    }
    if (type == 0)
    {
      pipex->fd = open(argv[4], O_WRONLY | O_CREAT, 0777);
      if (pipex->fd == -1)
       return (ft_putstr_fd("\nNo such file or directory", 1), -1);
    }
  return (0);
}



int ft_child_process(t_pipex *pipex, char *argv[], char *env[])
{ 
    get_cmd(pipex, argv[2]);
    ft_path(pipex, &pipex->cmds[0], env);
    if ((open_in_out_files(pipex, argv, 1)) == -1)
      return (-1);
    dup2(pipex->fd, 0);
    dup2(pipex->pipe_fd[1], 1);
    close(pipex->pipe_fd[0]);
    exec_cmd(pipex, env);
    close(pipex->fd);
    return (0);
}

int ft_parent_process(t_pipex *pipex, char *argv[], char *env[])
{
  get_cmd(pipex, argv[3]);
  ft_path(pipex, &pipex->cmds[0], env);
  if ((open_in_out_files(pipex, argv, 0)) == -1)
    return (-1);
  dup2(pipex->fd, 1);
  dup2(pipex->pipe_fd[0], 0);
  close(pipex->pipe_fd[1]);
  exec_cmd(pipex, env);
  close(pipex->fd);
  return (0);
}

int main(int argc, char *argv[], char *env[])
{
  t_pipex pipex;
  pid_t process;
  int intwait;
  if (argc != 5)
    return (ft_putstr_fd("<file \"cmd1\" \"cmd2\" file2>", 1), -1);
  pipe(pipex.pipe_fd);
  process = fork();
  if (process < 0)
    return (perror("fail"),1);
  unlink(argv[(argc - 1)]);
  if (process == 0)
  {
    waitpid(process, &intwait, WUNTRACED );
    ft_child_process(&pipex, argv, env);
  }
  else
  {
    waitpid(process, &intwait, WUNTRACED );
    ft_parent_process(&pipex, argv, env);  
  }
  return (ft_cleanup(&pipex), 0);
}
