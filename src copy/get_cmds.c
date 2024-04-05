/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:29:28 by nrobinso          #+#    #+#             */
/*   Updated: 2024/04/05 15:46:30 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	clean_cmd_path(t_pipex	*pipex)
{
	int	flag;
	int	i;
	int	j;

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
		return (-1);
	while (pipex->cmds[0][i] != '/')
		i--;
	i++;
	while (pipex->cmds[0][i])
	{
		pipex->cmds[0][j++] = pipex->cmds[0][i++];
	}
	pipex->cmds[0][j] = '\0';
	return (0);
}


int	get_cmd(t_pipex *pipex, char *argv)
{

	pipex->cmds = ft_split(argv, ' ');
	if (!pipex->cmds[0])
		return (-1);
	if ((access(pipex->cmds[0], F_OK | R_OK)) == 0)
		clean_cmd_path(pipex);
	return (0);
}


void	exec_cmd(t_pipex *pipex, int i, char *argv[], char *env[])
{
	int	ret;
	ret = -1;
	if (pipex->uni_path_flag == 0)
	{
		if ((get_cmd(pipex, argv[i])) == -1)
		{
			
			ft_path(pipex, "null", env);	
			ft_exec_cmd_error(pipex, "\npipex: permission denied: ");
			exit(127);
		}
		else
			ft_path(pipex, pipex->cmds[0], env);
	}
	if (pipex->valid_cmd == 0)
	{
		pipex->valid_cmd = 1;
		ret = execve(pipex->path, pipex->cmds, env);
	}
	if (ret == -1)
	{
		ft_exec_cmd_error(pipex, "\npipex: command not found: ");	
		exit(127);
	}
}








// /* functions for constructiob */

// void	print_double_tab(char *tab[])
// {
// 	int i;

// 	i = 0;

// 	while (tab && tab[i])
// 	{
// 		printf("%s\n", tab[i]);
// 		i++;
// 	}	
// }

// void print_cmd_path(t_pipex *pipex)
// {

// 	ft_putchar_fd('\n', 1);
// 	ft_putstr_fd(pipex->path, 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putstr_fd(pipex->cmds[0], 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putstr_fd(pipex->cmds[1], 1);
// 	ft_putchar_fd('\n', 1);
// 	// ft_putstr_fd(pipex->uni_path, 1);
// 	// ft_putchar_fd('\n', 1);


// }