/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:13:43 by armartir          #+#    #+#             */
/*   Updated: 2023/03/18 13:44:51 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_s(char **str)
{
	free(*str);
	*str = 0x0;
}

void	free_d(char ***addr)
{
	size_t	i;

	i = 0;
	if (*addr)
	{
		while ((*addr)[i])
		{
			free_s(&((*addr)[i]));
			i++;
		}
		free(*addr);
		addr = 0;
	}
}