/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions_autorised.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:54:44 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/27 09:52:05 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <fcntl.h>
// #include <sys/wait.h>

// int main(int argc, char const *argv[])
// {
	
// 	int open(const char *__path, int __oflag, ...); 			// - fcntl.h
// 	int close(int fd);											// - unistd.h
// 	ssize_t read(int __fd, void *__buf, size_t __nbytes) 		// - unsstd.h
// 	ssize_t write(int fildes, const void *buf, size_t nbyte);	// - unistd.h
//  void *malloc(size_t size); - stdlib.h						// - stdlib.h
// 	void free(void *ptr);										// - stdlib.h
// 	void perror(const char *s);									// - stdio.h
// 	char *strerror(int errnum);									// - string.h
// 	int access(const char *path, int amode);					// - unistd.h
// 	int dup(int fildes);										// - unistd.h
// 	int dup2(int fildes, int fildes2);							// - unistd.h
// 	int execv(const char *path, char *const argv[]);			// - unistd.h
// 	void exit(int status);										// - stdlib.h
// 	pid_t fork(void);											// - unistd.h
// 	int pipe(int fildes[2]);									// - unistd.h
// 	unlink, int unlink(const char *path);						// - unistd.h
// 	pid_t wait(int *stat_loc);									// - sys/wait.h
// 	pid_t waitpid(pid_t pid, int *stat_loc, int options);		// - sys/wait.h

// 	return 0;
// }




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

