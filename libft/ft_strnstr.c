/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:50:25 by armartir          #+#    #+#             */
/*   Updated: 2023/01/18 14:50:26 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	needle_len;
	char	*str;

	needle_len = ft_strlen(needle);
	if (0 == needle_len)
		return ((char *)haystack);
	i = 0;
	str = (char *)haystack;
	if (!haystack && len == 0)
		return (NULL);
	if ((len == 0 && haystack == needle) || (haystack == needle))
		return ((char *)(haystack));
	while (str[i] != '\0' && i < len)
	{
		c = 0;
		while (str[i + c] != '\0' && needle[c] != '\0'
			&& str[i + c] == needle[c] && i + c < len)
			c++;
		if (c == needle_len)
			return (str + i);
		i++;
	}
	return (0);
}
