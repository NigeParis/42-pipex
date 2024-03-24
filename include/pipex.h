/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:31:15 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/21 14:50:06 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "../libft/libft.h"
# include "../ft_printf/src/ft_printf.h"



typedef struct s_pipex
{
    int     path_nb;
    char    **paths;
    char    *path_cmd;
    char    *path;

}   t_pipex;


int ft_get_line_nb(char pathname[], char *env[]);
char **ft_get_paths(char *paths);




#endif
