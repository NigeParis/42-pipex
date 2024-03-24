/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:01:13 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/24 10:08:19 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int ft_get_line_nb(char pathname[], char *env[])
{
  int i;
  int j;

  i = 0;
  j = 0;
  if (!pathname || !env)
    return (-1);
  while (env && env[i])
  {
    
    while (env[i][j] == pathname[j] && j < 6)      
    {
      j++;  
    }
    if (j == 5 && j == ft_strlen(pathname))
      return (i);
    j = 0;
    i++;
  }
  return (i);
}

char **ft_get_paths(char *paths)
{
  char *line;
  char  **tab;
  int   i;
  int   j;

  i = 5;
  j = 0;
  if (!paths)
    return (NULL);
  line = ft_strdup(paths);
  if (!line)
    return (NULL);
  while (paths && paths[i])
  {
    line[j] = paths[i];
    j++;
    i++;
  }
  line[j] = ':';
  line[j+1] = '\0';
  tab = ft_split(line, ':');
  ft_free_tab(line);
  return (tab);
}