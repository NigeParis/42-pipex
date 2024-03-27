/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:45:37 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/27 09:46:53 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"


void  ft_cleanup(t_pipex *pipex)
{
    ft_free_double_tab(pipex->cmds);
    ft_free_double_tab(pipex->paths);
    ft_free_tab(pipex->path);
    ft_free_tab(pipex->path_cmd);
}


int ft_child_process(t_pipex *pipex, int argc, char *argv[], char *env[])
{ 
    get_cmd(pipex, argc, argv[2], env);
    ft_printf("\nChild - Process\n");
    ft_path(pipex, &pipex->cmds[0], env);
    pipex->fd = open(argv[1], O_RDONLY);
    if (pipex->fd == -1)
     return (ft_putstr_fd("\nNo such file or directory", 1), -1);
    dup2(pipex->fd, 0);
    dup2(pipex->pipe_fd[1], 1);
    close(pipex->pipe_fd[0]);
    exec_cmd(pipex, env);

    return (0);
}

int ft_parent_process(t_pipex *pipex, int argc, char *argv[], char *env[])
{
  get_cmd(pipex, argc, argv[3], env);
  ft_printf("\nParent - Process\n");
  ft_path(pipex, &pipex->cmds[0], env);
  pipex->fd = open(argv[4], O_WRONLY | O_RDONLY | O_CREAT, 0777);
  if (pipex->fd == -1)
    return (ft_putstr_fd("\nNo such file or directory", 1), -1);
  dup2(pipex->fd, 1);
  dup2(pipex->pipe_fd[0], 0);
  close(pipex->pipe_fd[1]);
  exec_cmd(pipex, env);
  return (0);
}

int main(int argc, char *argv[], char *env[])
{
  t_pipex pipex;
  pid_t process;
  int intwait;
  if (argc != 5)
    return (ft_putstr_fd("<file \"cmd1\" \"cmd2\" file2>", 1), -1);
  pipe(pipex.pipe_fd);
  process = fork();
  if (process < 0)
    return (perror("fail"),1);
  if (process == 0)
  {
    waitpid(process, &intwait, WUNTRACED );
    unlink(argv[4]);
    ft_child_process(&pipex, argc, argv, env);
  }
  else
  {
    waitpid(process, &intwait, WUNTRACED );
    ft_parent_process(&pipex, argc, argv, env);  
  }
  return (ft_cleanup(&pipex), 0);
}



/* ----------------------------------------------------------------------------------- */

//child and parent process

// void fork_child_parent(void)
// {
//   pid_t process;
//   int   intwait;

//   intwait = 0;
//   process = fork();
//   if(process < 0)
//   {
//     perror("fail");
//     exit(1);
//   }
//   else if (process == 0)
//     ft_putstr_fd("\nChild :", 1);
//     wait(NULL);
//     ft_putstr_fd("\nParent:", 1);
//   }
//   ft_putnbr_fd(process, 1);
  // WIFSIGNALED(intwait);
  // psignal(WTERMSIG(intwait), "\nExit signal");
  // waitpid(process, &intwait, WUNTRACED );
    
//}

// int main(void)
// {
//     fork_child_parent();
//     return (0);
// }

/* ----------------------------------------------------------------------------------- */

//function execve() passes a cmd to shell and executes

// use split with env to find the path to cmd bin:
// loop through to test each path until cmd executes (returns (0)) on execution
// check end of file - cmd or path not good


// int main(void)
// {
//   int ret;
//   char *cmd[] = {"ls", "-la", (char *)0 };
// //  char *env[] = {"HOME = /home/nrobinso", "LOGNAME=nrobinso", (char *)0 };
//   char *env[] = {"/bin/ls", (char *)0 };

//   ret = execve (env[0], cmd, env); 
  

//   return (0);
// }


/* ----------------------------------------------------------------------------------- */

// call twice same function with fork()
// int main()
// {
//     pid_t p = fork();
//     if(p<0){
//       exit(1);
//     }
//     ft_printf("Hello, process_id(pid) = %d \n",getpid());
//     ft_printf("world!, process_id(pid) = %d \n",getpid());
//     return 0;
// }

/* ----------------------------------------------------------------------------------- */
