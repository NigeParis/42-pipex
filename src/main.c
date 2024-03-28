/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:45:37 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/28 22:57:01 by nrobinso         ###   ########.fr       */
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

int ft_child_process(t_pipex *pipex, char *argv[], char *env[])
{ 
    get_cmd(pipex, argv[2]);
    ft_path(pipex, &pipex->cmds[0], env);
    pipex->fd = open(argv[1], O_RDONLY);
    if (pipex->fd == -1)
     return (ft_putstr_fd("\nNo such file or directory", 1), -1);
    dup2(pipex->fd, 0);
    dup2(pipex->pipe_fd[1], 1);
    close(pipex->pipe_fd[0]);
    exec_cmd(pipex, env);
    return (0);
}

int ft_parent_process(t_pipex *pipex, char *argv[], char *env[], int process)
{
  if (!process)
  {
    get_cmd(pipex, argv[3]);
    ft_path(pipex, &pipex->cmds[0], env);
    pipex->fd = open(argv[4], O_WRONLY | O_RDONLY | O_CREAT, 0777);
    if (pipex->fd == -1)
    {
      ft_putstr_fd("Error\nNo such file or directory", 1);
      exit (1);
    } 
    dup2(pipex->fd, 1);
    dup2(pipex->pipe_fd[0], 0);
    close(pipex->pipe_fd[1]); 
    exec_cmd(pipex, env);
  }
  return (0);
}

int main(int argc, char *argv[], char *env[])
{
  t_pipex pipex;
  pid_t   process;
  int     intwait;
  
  if (argc != 5)
    return (ft_putstr_fd("Error\narguments missing or too many <file \"cmd1\" \"cmd2\" file2>\n", 1), -1);
  if (pipe(pipex.pipe_fd) == -1)
    return (-1); 
  process = fork();
  if (process < 0)
    return (perror("fail"),1);
  if (process == 0)
  {
    waitpid(process, &intwait, WUNTRACED );
    unlink(argv[4]);
    ft_child_process(&pipex, argv, env);
  }
  else
  {
    waitpid(process, &intwait, WUNTRACED );
    process = fork();
    ft_parent_process(&pipex, argv, env, process);  
  }
  return (0);
}

