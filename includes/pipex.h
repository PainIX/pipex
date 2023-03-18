/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:13:19 by armartir          #+#    #+#             */
/*   Updated: 2023/03/18 13:39:29 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
// TODO: delete stdio
# include <stdio.h>

# define HERE_DOC ".here_doc"

// Validation
void	perm_check(int *ac, char ***av);
void    validation(int *ac, char ***av);

// Here_Doc
void	wait_limiter(char *limiter, int fd);
void	here_doc(int *ac, char ***av);

// Utils
void	write_error(int errno, char *msg_0, char *msg_1);
void	free_s(char **str);
void	free_d(char ***addr);
void	fd_dup(int fd_f, int fd_to);

#endif