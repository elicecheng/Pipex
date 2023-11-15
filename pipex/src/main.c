/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheng <jucheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:05:56 by jucheng           #+#    #+#             */
/*   Updated: 2023/09/14 10:16:28 by jucheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (ac != 5)
	{
		perror("Error: Input invalid");
		exit(1);
	}
	if (pipe(fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	else if (pid == 0)
		child_process(fd, av[1], av[2], envp);
	parent_process(fd, av[4], av[3], envp);
	return (0);
}

/* < file1 (av[0]) cmd1(av[1]) | cmd2(av[2]) > file2(av[3]) 
	child process id = 0
*/