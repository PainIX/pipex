/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:43:13 by armartir          #+#    #+#             */
/*   Updated: 2023/03/15 16:07:55 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	write_error(int errno, char *msg_0, char *msg_1)
{
	char	*error;

// TODO: add additional messages
	(void)msg_0;
	(void)msg_1;
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
		ft_putstr_fd("\n", 2);
		ft_putstr_fd(msg_1, 2);
	}
	ft_putstr_fd("\n", 2);
	if (errno < 128)
		exit(errno);
}

void	perm_check(int *ac, char ***av)
{
	int	last_index;

	last_index = ((*ac) - 1);
	if (ft_strcmp("here_doc",(*av)[1])
		&& access((*av)[1], F_OK))
			write_error(2, (*av)[1], 0);
	if (ft_strcmp("here_doc",(*av)[1])
		&& access((*av)[1], R_OK))
	{
		if (!(access((*av)[last_index],F_OK))
			&& access((*av)[last_index],W_OK))
				write_error(13, (*av)[1], (*av)[last_index]);
			write_error(13, (*av)[1], 0);
	}
	if (access((*av)[last_index],F_OK)
		&& access((*av)[last_index],W_OK))
			write_error(13, (*av)[last_index], 0);
}

void    validation(int *ac, char ***av)
{
	// int	fd0;
	// int	fd1;
	int	last_index;

	last_index = ((*ac) - 1);
	perm_check(ac, av);
}

int main(int argc, char **argv, char **envp)
{
	(void)argv;
	(void)envp;
	(void)argc;
	if (argc < 5)
		return (1);
	validation(&argc, &argv);
    // printf ("stea:   %d \n",access(argv[1], F_OK));
	// for(int i = 0;i < 129; i++)
	// 	printf ("%d:%s \n",i,strerror(i));
	// printf ("hres: %d  \n", !(access(argv[1],F_OK)));
	return 0;
}
