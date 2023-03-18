/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:43:13 by armartir          #+#    #+#             */
/*   Updated: 2023/03/18 17:29:43 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int main(int argc, char **argv, char **envp)
{
	char	**paths;

	if (argc < 5)
		return (1);
	validation(&argc, &argv);
    paths = find_path(envp);
	
	// printf ("stea:   %d \n",access(argv[1], F_OK));
	// for(int i = 0;i < 129; i++)
	// 	printf ("%d:%s \n",i,strerror(i));
	// printf ("hres: %d  \n", !(access(argv[1],F_OK)));
	// unlink(HERE_DOC);
	return 0;
}
