/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:15:21 by sogabrie          #+#    #+#             */
/*   Updated: 2023/03/14 16:44:56 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		s_len(char *ptr);
char	*char_n(char *ptr);
char	*get_and_clean(char *ptr);
char	*get_and_clean_ptr(char	*ptr);
char	*s_cp(char *s1, char *s2, int i);

#endif
