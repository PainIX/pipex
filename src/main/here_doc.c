/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:26:29 by armartir          #+#    #+#             */
/*   Updated: 2023/03/26 15:41:32 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_limiter(char *limiter, int fd)
{
	char	*buf;

	write(1, ">", 1);
	while (1)
	{
		buf = get_next_line(0);
		if (!buf)
			write_error(12, 0, 0);
		if (!(ft_strncmp(buf, limiter, ft_strlen(limiter))))
		{
			free_s(&buf);
			return ;
		}
		else
			write(fd, buf, ft_strlen(buf));
		write(1, ">", 1);
		free_s(&buf);
	}
}

void	here_doc(int *ac, char ***av)
{
	int		fd0;

	fd0 = open(HERE_DOC, O_WRONLY | O_CREAT | O_TRUNC, 0755);
	wait_limiter((*av)[2], fd0);
	perm_check(ac, av);
	close(fd0);
	fd0 = open(HERE_DOC, O_RDONLY);
	fd_dup(fd0, 0);
	close(fd0);
	*ac -= 4;
	*av += 3;
}
