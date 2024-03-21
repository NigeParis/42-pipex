/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:45:37 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/21 16:42:42 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
//   else
//   {
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


int main(void)
{
  int ret;
  char *cmd[] = {"ls", "-la", (char *)0 };
 // char *env[] = {"HOME = /home/nrobinso", "LOGNAME=nrobinso", (char *)0 };
  char *env[] = {"/bin/ls", (char *)0 };

  ret = execve (env[0], cmd, env); 
  

  return (0);
}


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
