/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:48:32 by armartir          #+#    #+#             */
/*   Updated: 2023/01/18 14:48:33 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_ch_count(char const *s, char c)
{
	size_t	ch_count;
	int		i;

	i = 0;
	ch_count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (i > 0 && s[i] && s[i - 1] == c)
			ch_count++;
		if (s[i])
			i++;
	}
	if (s[0] != c)
		ch_count++;
	if (ch_count == 0 && s[i - 1] == c)
		return (0);
	return (ch_count);
}

static char	**get_str_mal(char **ptr, const char *s, char c, size_t count)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (s[++j])
	{
		if (s[j] != c)
			count++;
		else if (j > 0 && s[j - 1] != c)
		{
			ptr[i] = (char *)malloc(sizeof(char) * (count + 1));
			if (!ptr[i])
				return (0);
			count = 0;
			i++;
		}
		if (s[j + 1] == '\0' && s[j] != c)
		{
			ptr[i] = (char *)malloc(sizeof(char) * (count + 1));
			if (!ptr)
				return (0);
		}
	}
	return (ptr);
}

static char	**fill_strs(char **ptr, const char *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[k])
	{
		if (s[k] != c)
			ptr[i][j++] = s[k];
		else if (k > 0 && s[k - 1] != c)
		{
			ptr[i][j] = '\0';
			j = 0;
			i++;
		}
		if (s[k + 1] == '\0' && s[k] != c)
			ptr[i][j] = '\0';
		k++;
	}
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		ch_count;

	if (!s || !*s)
	{
		str = (char **)malloc(sizeof(char *) * 1);
		if (!str)
			return (NULL);
		*str = (void *) 0;
		return (str);
	}
	ch_count = get_ch_count(s, c);
	str = (char **)malloc(sizeof(char *) * (ch_count + 1));
	if (!str)
		return (0);
	if (get_str_mal(str, s, c, 0) != 0)
		fill_strs(str, s, c);
	else
	{
		free(str);
		return (NULL);
	}
	str[ch_count] = (void *)0;
	return (str);
}
