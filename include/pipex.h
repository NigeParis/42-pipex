/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:31:15 by nrobinso          #+#    #+#             */
/*   Updated: 2024/04/02 13:22:30 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
    int     valid_cmd;
    int     all_cmd_valid;
    int     nbr_cmds;
    int     nb_argc;
    int     parse_flag;

}   t_pipex;


int     ft_get_line_nb(char pathname[], char *env[]);
char    **ft_get_paths(char *paths);
int     ft_path_error (t_pipex *pipex);
int     ft_path(t_pipex *pipex, char *cmd, char **env);
int     get_cmd(t_pipex *pipex, char *argv);
void    exec_cmd(t_pipex *pipex, int i, char *argv[], char *env[]);
void    ft_cleanup(t_pipex *pipex, int type);
void    close_fd(t_pipex *pipex, int type);
void	ft_cleanup_helper(t_pipex *pipex, int type);
void	ft_init(t_pipex *pipex, int argc, char *argv[]);

void	print_double_tab(char *tab[]); //construction tool


#endif
