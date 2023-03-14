/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:52:49 by armartir          #+#    #+#             */
/*   Updated: 2023/01/18 14:52:50 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		len;

	len = ft_strlen(s);
	ch = (unsigned char)c;
	while (len >= 0)
	{
		if (s[len] == ch)
		{
			return ((char *)(s + len));
		}
		--len;
	}
	return (0);
}
