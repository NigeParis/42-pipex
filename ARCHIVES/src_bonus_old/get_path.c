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

#include "../include/pipex_bonus.h"

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
    if (j == 5 && j == (int)ft_strlen(pathname))
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

// int ft_path(t_pipex *pipex, char **cmd, char **env)
// {
//   int i;
  
//   i = 0; 
//   char *tmp_path_cmd;
//   char *tmp_path;


//   ft_printf("\n--------path------%s-------------\n", pipex->path);
//   ft_printf("\n--------path cmd------%s---------\n", pipex->path_cmd);

//   pipex->path_nb = ft_get_line_nb("PATH=", env);
//   pipex->paths = ft_get_paths(env[pipex->path_nb]);
//   if (pipex->paths[i] == NULL)
//       return (ft_path_error(pipex));
//   tmp_path_cmd = ft_strjoin(pipex->paths[0], "/");
//   tmp_path = ft_strjoin(tmp_path_cmd, cmd[0]);
//   ft_free_tab(tmp_path_cmd);
//   free(pipex->path);
//   pipex->path = tmp_path;
//   while (access(pipex->path, F_OK | R_OK) != 0)
//   {
     
//     i++;
//     tmp_path_cmd = ft_strjoin(pipex->paths[i], "/"); 
//     tmp_path = ft_strjoin(tmp_path_cmd, cmd[0]);
//     ft_free_tab(tmp_path_cmd);
//     free(pipex->path);
//     pipex->path = tmp_path;
//     if (pipex->paths[i] == NULL)
//     {
// //     ft_printf("\n----------------------exit ft_path[i] is NULL \n");
//       return (ft_path_error(pipex));
//     }
// //   ft_printf("\n2:%s\n", pipex->path);
//   }
//   return (0);
// }





int ft_path(t_pipex *pipex, char *cmd, char **env)
{
  int i;
  
  i = 0;  

  ft_free_double_tab(pipex->paths);
  ft_free_tab(pipex->path_cmd);
  ft_free_tab(pipex->path);
  pipex->path_nb = ft_get_line_nb("PATH=", env);
  pipex->paths = ft_get_paths(env[pipex->path_nb]);
  if (pipex->paths[i] == NULL)
      return (ft_path_error(pipex));

  pipex->path_cmd = ft_strjoin(pipex->paths[0], "/");
  pipex->path = ft_strjoin(pipex->path_cmd, cmd);

  while (access(pipex->path, F_OK | R_OK) != 0)
  {
    ft_free_tab(pipex->path_cmd);
    ft_free_tab(pipex->path);
    i++;
    pipex->path_cmd = ft_strjoin(pipex->paths[i], "/"); 
    pipex->path = ft_strjoin(pipex->path_cmd, cmd);

    if (pipex->paths[i] == NULL)
      return (ft_path_error(pipex));
  }
  return (0);
}



// int ft_path(t_pipex *pipex, char **cmd, char **env)
// {
//   int i;
  
//   i = 0;  
//   pipex->path_nb = ft_get_line_nb("PATH=", env);
//   pipex->paths = ft_get_paths(env[pipex->path_nb]);
//   if (pipex->paths[i] == NULL)
//       return (ft_path_error(pipex));
//   pipex->path_cmd = ft_strjoin(pipex->paths[0], "/");
//   pipex->path = ft_strjoin(pipex->path_cmd, cmd[0]);
//   while (access(pipex->path, F_OK | R_OK) != 0)
//   {
//     ft_free_tab(pipex->path_cmd);
//     ft_free_tab(pipex->path);
//     i++;
//     pipex->path_cmd = ft_strjoin(pipex->paths[i], "/"); 
//     pipex->path = ft_strjoin(pipex->path_cmd, cmd[0]);
//     if (pipex->paths[i] == NULL)
//       return (ft_path_error(pipex));
//   }

//   ft_free_tab(pipex->path_cmd);
//   return (0);
// }