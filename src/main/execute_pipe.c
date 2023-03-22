/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:56:57 by armartir          #+#    #+#             */
/*   Updated: 2023/03/22 22:58:48 by armartir         ###   ########.fr       */
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

	cmnd = ft_strjoin("/", cmnd);
	while (*paths)
	{
		if (!(access(cmnd, F_OK)))
		{
			if (!tmp)
				free(tmp);
			return (cmnd);
		}
		tmp = ft_strjoin(*paths, cmnd);
		if (!(access(tmp, F_OK)))
		{
			free (cmnd);
			return (tmp);
		}
		free(tmp);
		paths++;
	}
	free(cmnd);
	return (0);
}

void	my_unlink(void)
{
	unlink(HERE_DOC);
	unlink(".tmp");
}

void	execute_pipe(char **paths, int ac, char **av)
{
	char	**cmnd;
	int		ind;
	char	*tmp;
	pid_t	pid;

	ind = -1;
	while (ind++ < ac)
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
			else
				wait(NULL);
		}
		if (!tmp)
			write_error(129, *cmnd, 0);
		free_d(&cmnd);
		free_s(&tmp);
	}
}
