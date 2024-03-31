/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:52:01 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/30 15:36:01 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_clean_output_file(t_pipex *pipex, int argc, char *argv[], int type)
{
	int	fd;

	if (argc != 5 || (argv[2][0] == 0 || argv[3][0] == 0))
	{
		ft_putstr_fd(
			"Error\nparse error near\n<file \"cmd1\" \"cmd2\"file2>\n", 1);
		exit(1);
	}
	fd = open(argv[argc - 1], O_RDONLY, 0666);
	if (!fd || fd == -1)
	{
		ft_printf("Error\nfile in not opened\n");
		close(fd);
		open_in_out_files(pipex, argc, argv, type);
		ft_close_fd(pipex, 1);
		return (1);
	}
	close(fd);
	unlink(argv[argc - 1]);
	open_in_out_files(pipex, argc, argv, type);
	ft_close_fd(pipex, 1);
	return (0);
}

int	ft_path_error(void)
{
	ft_putstr_fd("\nError command not found", 1);
	return (1);
}

void	ft_cleanup(t_pipex *pipex)
{
	ft_free_double_tab(pipex->cmds);
	ft_free_double_tab(pipex->paths);
	ft_free_tab(pipex->path);
	ft_free_tab(pipex->path_cmd);
}

int	open_in_out_files(t_pipex *pipex, int argc, char *argv[], int type)
{
	if (type == 1)
	{
		pipex->fd = open(argv[1], O_RDONLY, 0666);
		if (pipex->fd == -1)
		{
			ft_close_fd(pipex, 1);
			return (ft_putstr_fd("\nNo such file or directory\n", 1), -1);
		}
	}
	if (type == 0)
	{
		pipex->fd = open(argv[argc -1], O_WRONLY | O_CREAT, 0666);
		if (pipex->fd == -1)
		{
			ft_close_fd(pipex, 1);
			return (ft_putstr_fd("\nNo such file or directory\n", 1), -1);
		}
	}
	return (0);
}

void	ft_close_fd(t_pipex *pipex, int group)
{
	if (group == 1)
		close(pipex->fd);
	if (group == 2)
	{
		close(pipex->pipe_fd[0]);
		close(pipex->pipe_fd[1]);
	}
	if (group == 3)
	{
		close(pipex->fd);
		close(pipex->pipe_fd[0]);
		close(pipex->pipe_fd[1]);
	}
}
