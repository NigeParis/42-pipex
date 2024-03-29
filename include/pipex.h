/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:31:15 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/29 10:59:10 by nrobinso         ###   ########.fr       */
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
	int		path_nb;
	int		fd;
	int		pipe_fd[2];
	char	**paths;
	char	*path_cmd;
	char	*path;
	char	**cmds;
}	t_pipex;

int		open_in_out_files(t_pipex *pipex, int argc, char *argv[], int type);
int		ft_clean_output_file(t_pipex *pipex, int argc, char *argv[], int type);
int		ft_get_line_nb(char pathname[], char *env[]);
int		ft_path_error(void);
int		ft_path(t_pipex *pipex, char **cmd, char **env);
int		get_cmd(t_pipex *pipex, char *argv);
void	exec_cmd(t_pipex *pipex, char *env[]);
void	ft_cleanup(t_pipex *pipex);
char	**ft_get_paths(char	*paths);
void	ft_close_fd(t_pipex *pipex, int group);
#endif
