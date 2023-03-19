/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:21:34 by armartir          #+#    #+#             */
/*   Updated: 2023/03/19 22:55:46 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fd_dup(int fd_f, int fd_to)
{
	dup2(fd_f, fd_to);
	close(fd_f);
}

char	**find_path(char **env)
{
	char	**paths;
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = "PATH=";
	while (env[i])
	{
		if (ft_strncmp(env[i], tmp, 5))
			i++;
		else
			break ;
	}
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		i++;
	}
	return (paths);
}

void	write_error(int errno, char *msg_0, char *msg_1)
{
	char	*error;

	if (errno == 129)
		error = "Command not found: ";
	else
		error = strerror(errno);
	ft_putstr_fd("zsh: ", 2);
	ft_putstr_fd(error, 2);
	if (msg_0)
	{
		if (errno != 129)
			ft_putstr_fd(": ", 2);
		ft_putstr_fd(msg_0, 2);
	}
	if (msg_1)
	{
		ft_putstr_fd(" ", 2);
		ft_putstr_fd(msg_1, 2);
	}
	ft_putstr_fd("\n", 2);
	// if (errno < 128)
	// 	exit (errno);
}

int	perm_check(int *ac, char ***av)
{
	int	last_index;

	last_index = ((*ac) - 1);
	if (!(ft_strcmp("here_doc", (*av)[1]))
		&& access((*av)[last_index], W_OK))
		unlink(HERE_DOC);
	if (ft_strcmp("here_doc", (*av)[1])
		&& access((*av)[1], F_OK))
		write_error(2, (*av)[1], 0);
	if (!(access((*av)[last_index], F_OK))
		&& access((*av)[last_index], W_OK))
		write_error(13, (*av)[last_index], 0);
	if (ft_strcmp("here_doc", (*av)[1])
		&& access((*av)[1], R_OK))
	{
		write_error(13, (*av)[1], 0);
		return (0);
	}
	return (1);
}

void	validation(int *ac, char ***av)
{
	int	fd0;
	int	fd1;
	int	last_index;

	last_index = (*ac - 1);
	if (!(ft_strcmp((*av)[1], "here_doc")))
	{
		fd1 = open((*av)[last_index], O_WRONLY | O_CREAT | O_APPEND, 0755);
		here_doc(ac, av);
		fd_dup(fd1, 1);
		return ;
	}
	if (!(perm_check(ac, av)))
	{
		*av += 3;
		*ac -= 4;
		return ;
	}
	fd0 = open((*av)[1], O_RDONLY);
	fd1 = open((*av)[last_index], O_WRONLY | O_TRUNC | O_CREAT, 0755);
	fd_dup(fd0, 0);
	fd_dup(fd1, 1);
	*av += 2;
	*ac -= 3;
}
