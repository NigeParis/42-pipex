/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:45:37 by nrobinso          #+#    #+#             */
/*   Updated: 2024/04/09 18:11:14 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_init(t_pipex *pipex, int argc, char *argv[])
{
	pipex->path = 0;
	pipex->paths = 0;
	pipex->path_cmd = 0;
	pipex->cmds = 0;
	pipex->valid_cmd = 0;
	pipex->all_cmd_valid = 0;
	pipex->nbr_cmds = (argc - 3);
	pipex->nb_argc = argc;
	pipex->parse_flag = 0;
	pipex->fdin = -1;
	pipex->fdout = -1;
	pipex->uni_path_flag = 0;
	pipex->uni_cmd = 0;
	pipex->uni_path = 0;
	pipex->cmd_not_flag = 0;
	ft_open_files(pipex, argc, argv);
}

void	ft_open_files(t_pipex *pipex, int argc, char *argv[])
{
	if (access(argv[1], F_OK) == -1)
	{
		perror(argv[1]);
		exit (0);
	}
	else if (access(argv[1], R_OK) == -1)
	{
		perror(argv[1]);
		exit (0);
	}
	if (access(argv[1], F_OK | R_OK) == 0)
		pipex->fdin = open(argv[1], O_RDONLY, 0777);
	pipex->fdout = open(argv[argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex->fdout == -1)
	{
		close_fd(pipex, 0);
		perror("outfile");
		exit (0);
	}
}

int	path_absolu_valid(t_pipex *pipex, char *argv[], int i)
{
	if (access(pipex->uni_path[0], F_OK | R_OK) == 0)
	{
		if ((get_cmd(pipex, argv[i])) == -1)
		{
			ft_putstr_fd("pipex: permission denied:", 1);
			ft_cleanup(pipex, 5);
			close_fd(pipex, 10);
			exit(127);
		}
		pipex->valid_cmd = 0;
		pipex->all_cmd_valid++;
		ft_cleanup(pipex, 8);
		pipex->path = ft_strdup(pipex->uni_path[0]);
		pipex->cmds = pipex->uni_path;
		return (1);
	}	
	return (0);
}

int	get_path_absolu(t_pipex *pipex, char *argv[], int i)
{
	int	j;

	j = 0;
	while (argv[i][j] != '\0' && argv[i][j] != ' ')
	{
		if (argv[i][j] == '/')
			pipex->uni_path_flag = 1;
		j++;
	}
	if (pipex->uni_path_flag)
	{
		if (pipex->uni_path)
			ft_free_double_tab(pipex->uni_path);
		pipex->uni_path = ft_split(argv[i], ' ');
		if (path_absolu_valid(pipex, argv, i))
			return (1);
		pipex->uni_path_flag = 0;
		pipex->valid_cmd = 1;
		ft_cleanup(pipex, 8);
		if (pipex->uni_path)
			ft_free_double_tab(pipex->uni_path);
	}
	return (0);
}

int	main(int argc, char *argv[], char *env[])
{
	t_pipex	pipex;
	int		i;

	i = 2;
	if (argc != 5)
	{
		ft_printf_fd(2, "pipex: format args \"file 1 cmd 1 cmd 2 file2\"\n");
		return (1);
	}
	ft_init(&pipex, argc, argv);
	while (i <= argc - 2)
	{
		make_pipe(&pipex, env, argv, i);
		close(pipex.pipe_fd[0]);
		close(pipex.pipe_fd[1]);
		ft_cleanup(&pipex, 8);
		i++;
	}
	while (wait(NULL) > 0)
		;
	ft_cleanup(&pipex, 8);
	close_fd(&pipex, 10);
	return (0);
}
