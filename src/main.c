/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:45:37 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/21 14:12:17 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/main.h"

#include <sys/types.h>
#include <unistd.h>


// function execve passes a cmd to shell and executes
int main(void)
{
  int ret;
  char *cmd[] = {"ll", "-la", (char *)0 };
  char *env[] = {"HOME = /home/nrobinso", "LOGNAME=nrobinso", (char *)0 };

  ret = execve ("/bin/ls", cmd, env); 
  

  return 0;
}

// call twice same function with fork
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
