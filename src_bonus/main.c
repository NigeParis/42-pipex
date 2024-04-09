/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:45:37 by nrobinso          #+#    #+#             */
/*   Updated: 2024/04/09 18:26:30 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

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
	pipex->doc = 0;
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

int	ft_pipex(t_pipex *pipex, int argc, char *argv[])
{
	if (argc < 5)
	{
		ft_printf_fd(2, "pipex: format args \"file1 cmd1 cmd2... file2\"\n");
		return (1);
	}
	ft_init(pipex, argc, argv);
	return (0);
}

void	cleanup_main_end(t_pipex *pipex)
{
	ft_heredoc_cleanup(pipex);
	ft_cleanup(pipex, 8);
	close_fd(pipex, 10);
}

int	main(int argc, char *argv[], char *env[])
{
	t_pipex	pipex;
	int		i;

	if (ft_strcmp (argv[1], "here_doc") == 0)
	{
		i = 3;
		if (ft_heredoc(&pipex, argc, argv))
			return (1);
	}
	else
	{
		i = 2;
		if (ft_pipex(&pipex, argc, argv))
			return (1);
	}
	while (i <= argc - 2)
	{
		ft_pipes(&pipex, argv, env, i);
		i++;
	}
	while (wait(NULL) > 0)
		;
	cleanup_main_end(&pipex);
	return (0);
}
