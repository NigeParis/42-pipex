/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:31:15 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/21 14:50:06 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "../libft/libft.h"
# include "../ft_printf/src/ft_printf.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_pipex
{
    int     path_nb;
    int     fdin;
    int     fdout;
    int     pipe_fd[2];
    char    **paths;
    char    *path_cmd;
    char    *path;
    char    **cmds;

}   t_pipex;


int ft_get_line_nb(char pathname[], char *env[]);
char **ft_get_paths(char *paths);
int ft_path_error (t_pipex *pipex);
int ft_path(t_pipex *pipex, char *cmd, char **env);
int get_cmd(t_pipex *pipex, char *argv);
void  exec_cmd(t_pipex *pipex, char *env[]);
void    ft_cleanup(t_pipex *pipex);


#endif