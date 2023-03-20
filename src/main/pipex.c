/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:43:13 by armartir          #+#    #+#             */
/*   Updated: 2023/03/20 14:56:56 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_cmnds(char *cmd_line, char **cmnds)
{
	pid_t		pid;
	int			fd[2];

	pipe(fd);
	pid = fork();
	if (pid)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		wait(NULL);
	}
	else
	{
		close (fd[0]);
		dup2(fd[1], 1);
		exit(execve(cmd_line, cmnds, NULL));
	}
}

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
	pid_t	pid;

	ind = 0;
	while (ind < ac)
	{
		cmnd = ft_split(av[ind], ' ');
		tmp = is_cmnd_exe(paths, *cmnd);
		if (ind != (ac - 1))
			pipe_cmnds(tmp, cmnd);
		else
		{
			pid = fork();
			if (!pid)
				exit(execve(tmp, cmnd, NULL));
		}
		if (!tmp)
			write_error(129, *cmnd, 0);
		ind++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;

	if (argc < 5)
		return (1);
	paths = find_path(envp);
	validation(&argc, &argv);
	if (!paths)
		return (0);
	execute_pipe(paths, argc, argv);
	unlink(HERE_DOC);
	unlink(".tmp");
	return (0);
}