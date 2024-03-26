/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:29:28 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/26 12:12:15 by nrobinso         ###   ########.fr       */
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
  return (0);
}

