/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:31:23 by nrobinso          #+#    #+#             */
/*   Updated: 2024/04/10 08:20:47 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_heredoc_init(t_pipex *pipex, int argc, char *argv[])
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
	pipex->doc = 1;
	pipex->pipe_doc[0] = 0;
	pipex->pipe_doc[1] = 0;
	pipex->fdout = open(argv[argc -1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (pipex->fdout == -1)
	{
		close_fd(pipex, 0);
		perror("outfile");
		exit (0);
	}
}

int	ft_heredoc(t_pipex *pipex, int argc, char *argv[])
{
	if (argc < 6)
	{
		ft_printf_fd(2, "pipex: format args \
			\"here_doc LIMITER cmd1 cmd2 file2\"\n");
		return (1);
	}
	ft_heredoc_init(pipex, argc, argv);
	ft_here_doc(pipex, argv);
	return (0);
}

void	ft_heredoc_cleanup(t_pipex *pipex)
{
	if (pipex->doc != 0)
	{
		if (pipex->pipe_doc[0] != -1)
			close(pipex->pipe_doc[0]);
		close_fd(pipex, 1);
	}
}

void	ft_here_doc(t_pipex *pipex, char *argv[])
{
	char	*str;
	int		ret;		

	str = NULL;
	ret = pipe(pipex->pipe_doc);
	if (ret < 0)
		perror("heredoc");
	while (1)
	{
		ft_printf("here_doc> ");
		str = get_next_line(0);
		if ((ft_strncmp(str, argv[2], ft_strlen(argv[2])) == 0))
		{
			if ((ft_strlen(str) - 1) == ft_strlen(argv[2]))
			{
				break ;
			}
		}
		ft_putstr_fd(str, pipex->pipe_doc[1]);
		ft_free_tab(str);
	}
	ft_free_tab(str);
	close(pipex->pipe_doc[1]);
}
