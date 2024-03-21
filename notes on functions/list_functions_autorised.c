/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions_autorised.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:54:44 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/21 13:25:11 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	
	int open (const char *__path, int __oflag, ...); 			// - fcntl.h
	int close (int fd);											// - unistd.h
	ssize_t read (int __fd, void *__buf, size_t __nbytes) 		// - unsstd.h
	ssize_t write(int fildes, const void *buf, size_t nbyte);	// - unistd.h
 	void *malloc(size_t size); - stdlib.h						// - stdlib.h
	void free(void *ptr);										// - stdlib.h
	void perror(const char *s);									// - stdio.h
	char *strerror(int errnum);									// - string.h
	int access(const char *path, int amode);					// - unistd.h
	dup, 
	dup2,
	execve, 
	exit, 
	fork, 
	pipe,
	unlink, 
	wait, 
	waitpid
	ft_printf
	get_next_line

	return 0;
}
