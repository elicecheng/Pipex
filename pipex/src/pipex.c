/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheng <jucheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:22:28 by jucheng           #+#    #+#             */
/*   Updated: 2023/09/09 14:56:40 by jucheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/*this function searches through the directories 
specified in the PATH environment variable, 
constructs potential full paths for the given command, 
checks if those paths correspond to existing executable files, 
and returns the first existing path found. 
If no existing path is found, it returns 0. */

static char	*find_path(char *cmd, char **envp)
{
	char	**tmp;
	char	*path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	tmp = ft_split(envp[i] + 5, ':');
	i = 0;
	while (tmp[i])
	{
		path = ft_strjoin(tmp[i], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	free(tmp);
	return (0);
}

/* exec function takes a command, splits it into parts, 
finds where the computer can run that command, 
tries to run it, handles any problems, and cleans up after itself. */

static void	exec(char *cmd, char **envp)
{
	char	*path;
	char	**av;

	av = ft_split(cmd, ' ');
	path = find_path(av[0], envp);
	if (execve(path, av, envp) == -1)
	{
		perror("Error: Could not execute execve");
		free(av);
		free(path);
		exit(1);
	}
	free(av);
	free(path);
}

void	child_process(int fd[], char *infile, char *cmd, char **envp)
{
	int	infd;

	infd = open(infile, O_RDONLY);
	if (infd == -1)
	{
		perror("Error: Failed to open input file");
		exit(1);
	}
	dup2(infd, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	exec(cmd, envp);
}

/*  O_RDONLY: Open for reading only
	O_WRONLY: Open for write only
	O_CREAT: Create the file if it doesn't exist
	O_TRUNC: Truncate (clear) the file if it already exists
	0666: File permissions - read and 
	write for owner and group, read-only for others */

void	parent_process(int fd[], char *outfile, char *cmd, char **envp)
{
	int	outfd;

	outfd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (outfd == -1)
	{
		perror("Error: Failed to open output file");
		exit(1);
	}
	dup2(outfd, 1);
	dup2(fd[0], 0);
	close (fd[1]);
	exec(cmd, envp);
}
