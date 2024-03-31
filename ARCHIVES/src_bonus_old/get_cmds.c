/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:29:28 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/28 20:33:00 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void clean_cmd_path(t_pipex *pipex)
{
  int flag;
  int i;
  int j;

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
  return ;
}



int get_cmd(t_pipex *pipex, char *argv)
{
  char  *tmp;

  ft_free_double_tab(pipex->cmds);
  tmp = ft_strdup(argv);
  pipex->cmds = ft_split(tmp, ' ');
  free(tmp);
  ft_printf("\n---..get_cmd '%s'....\n", pipex->cmds[0]);

  if ((access(pipex->cmds[0], F_OK | R_OK)) == 0)
  {
    clean_cmd_path(pipex);
  }
    return (0);
}


void  exec_cmd(t_pipex *pipex, char *env[])
{
  int status;


  status = execve(pipex->path, &pipex->cmds[0], env); 
  if (status == -1)
  {
    ft_free_double_tab(pipex->cmds);
    ft_free_double_tab(pipex->paths);
    ft_free_tab(pipex->path);
    ft_free_tab(pipex->path_cmd);
    exit (1);
  }
}

