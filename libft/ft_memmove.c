/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:46:43 by armartir          #+#    #+#             */
/*   Updated: 2023/01/18 14:46:45 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cdst;
	char	*csrc;
	int		i;

	if (!dst && !src)
		return (NULL);
	cdst = (char *)dst;
	csrc = (char *)src;
	i = (int)len - 1;
	if (dst > src)
	{
		while (i >= 0)
		{
			*(cdst + i) = *(csrc + i);
			i--;
		}
		return (dst);
	}
	else
		return (ft_memcpy(dst, src, len));
}
