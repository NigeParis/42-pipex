/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrobinso <nrobinso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:45:37 by nrobinso          #+#    #+#             */
/*   Updated: 2024/03/21 09:04:17 by nrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/main.h"

#include <sys/types.h>
#include <unistd.h>
int main()
{
    pid_t p = fork();
    if(p<0){
      exit(1);
    }
    ft_printf("Hello world!, process_id(pid) = %d \n",getpid());
    return 0;
}
