/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:29:28 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/26 23:02:27 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

clean_cmd_path(t_pipex *pipex)
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



int get_cmd(t_pipex *pipex, int argc, char *argv, char *env[])
{
  int   i;
  char  *line;
  char  *tmp;

  tmp = ft_strdup(argv);
 

  pipex->cmds = ft_split(tmp, ' ');
  ft_printf("\n---------------------------%s----\n", tmp);
  free(tmp);

  // make function Check cmds[0] pour /

  clean_cmd_path(pipex);

  ft_printf("\n%s", pipex->cmds[0]);
  
  return (0);
}

void  exec_cmd(t_pipex *pipex, char *env[])
{
  int ret;

  ret = execve(pipex->path, &pipex->cmds[0], env); 
  if (ret == -1)
  {
    ft_free_double_tab(pipex->cmds);
    ft_free_double_tab(pipex->paths);
    ft_free_tab(pipex->path);
    ft_free_tab(pipex->path_cmd);
    exit (1);
  }
}


