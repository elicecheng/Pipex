/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheng <jucheng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:53:53 by jucheng           #+#    #+#             */
/*   Updated: 2023/09/09 14:35:57 by jucheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sysexits.h>
# include <fcntl.h>

# include "ft_printf.h"
# include "libft.h"

void	parent_process(int fd[], char *outfile, char *cmd, char **envp);
void	child_process(int fd[], char *infile, char *cmd, char **envp);

#endif