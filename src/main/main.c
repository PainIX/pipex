/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:43:13 by armartir          #+#    #+#             */
/*   Updated: 2023/03/14 17:35:57 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void    validation(int ac, char ** av)
{
	int	valid;

	(void)ac;
	// if (!(ft_strncmp("here_doc", av[1], ft_strlen(av[1]))))
		
}

int main(int argc, char **argv, char **env)
{
	(void)env;
	if (!(argc < 5))
		validation(argc, argv);
    return 0;
}
