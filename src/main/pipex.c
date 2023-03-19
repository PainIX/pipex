/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:43:13 by armartir          #+#    #+#             */
/*   Updated: 2023/03/19 17:44:46 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>

char	*is_cmnd_exe(char **paths, char *cmnd)
{
	char		*tmp;

	while (*paths)
	{
		if (!(access(cmnd, F_OK)))
			return (cmnd);
		tmp = ft_strjoin(*paths, cmnd);
		if (!(access(tmp, F_OK)))
			return (tmp);
		paths++;
	}
	return (0);
}

void	execute_pipe(char **paths, int ac, char **av)
{
	char	**cmnd;
	int		ind;
	char	*tmp;
	pid_t		pid;
	int		fd[2];

	ind = 0;
	while (ind < ac)
	{
		cmnd = ft_split(av[ind], ' ');
		tmp = is_cmnd_exe(paths, *cmnd);
		if (tmp)
		{
			if (ind != (ac - 1))
			{
			pipe(fd);
			pid = fork();
			if (pid)
			{
			// printf ("example %s\n", tmp);
				close(fd[1]);
				dup2(fd[0], 0);
				wait(NULL);
			}
			else
			{
				close (fd[0]);
				dup2(fd[1], 1);
				exit(execve(tmp, cmnd, NULL));
			}
			}
			else
				exit(execve(tmp, cmnd, NULL));
		}
		ind++;
	}
}

int main(int argc, char **argv, char **envp)
{
	char	**paths;

	if (argc < 5)
		return (1);
	validation(&argc, &argv);
    paths = find_path(envp);
	if(!paths)
		return (0);
	execute_pipe(paths, argc, argv);
	// printf ("stea:   %d \n",access(argv[1], F_OK));
	// for(int i = 0;i < 129; i++)
	// 	printf ("%d:%s \n",i,strerror(i));
	// printf ("hres: %d  \n", !(access(argv[1],F_OK)));
	// unlink(HERE_DOC);
	return 0;
}
