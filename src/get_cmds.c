/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:29:28 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/26 22:08:17 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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


