/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:47:28 by armartir          #+#    #+#             */
/*   Updated: 2023/01/18 14:47:29 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	char			*ch_ptr;
	unsigned char	ch;
	size_t			i;

	ch_ptr = (char *)b;
	i = 0;
	ch = (unsigned char)c;
	while (i < n)
	{
		ch_ptr[i] = ch;
		i++;
	}
	return (b);
}
