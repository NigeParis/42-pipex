/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:45:37 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/26 13:37:43 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int main(int argc, char *argv[], char *env[])
{
  int ret;
  int i;
  t_pipex pipex;
  int fd;
  int pipe_fd[2];
  pid_t process;
  int intwait;

  i = 0;
  pipe(pipe_fd);
  process = fork();
  if (process < 0)
    return (perror("fail"),1);

  if (process == 0)
  {
    waitpid(process, &intwait, WUNTRACED );
    get_cmd(&pipex, argc, argv[2], env);
    ft_printf("\nChild - Process\n");
    ft_path(&pipex, &pipex.cmds[0], env);
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
     return (ft_putstr_fd("\nNo such file or directory", 1), -1);
    dup2(fd, 0);
    dup2(pipe_fd[1], 1);
    close(pipe_fd[0]);
    ret = execve(pipex.path, &pipex.cmds[0], env); 
  }
  else
  {
    waitpid(process, &intwait, WUNTRACED );
    get_cmd(&pipex, argc, argv[3], env);
    ft_printf("\nParent - Process\n");
    ft_path(&pipex, &pipex.cmds[0], env);
    fd = open(argv[4], O_WRONLY);
    if (fd == -1)
     return (ft_putstr_fd("\nNo such file or directory", 1), -1);
    dup2(fd, 1);
    dup2(pipe_fd[0], 0);
    close(pipe_fd[1]);

    ret = execve(pipex.path, &pipex.cmds[0], env); 
    
  }
  WIFSIGNALED(intwait);
  psignal(WTERMSIG(intwait), "\nExit signal");
  return (0);
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
