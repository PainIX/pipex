/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:48:49 by armartir          #+#    #+#             */
/*   Updated: 2023/01/18 14:48:50 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char			ch;
	unsigned int	i;

	i = 0;
	ch = (char)c;
	while (s[i])
	{
		if (s[i] == ch)
		{
			return ((char *)(s + i));
		}
		++i;
	}
	if (s[i] == ch)
	{
		return ((char *)(s + i));
	}
	return (0);
}
