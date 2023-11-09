/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:09:34 by mpitot            #+#    #+#             */
/*   Updated: 2023/11/09 14:17:30 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char **tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

size_t	ft_count_words(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (i == 0 || str[i - 1] == c)
		{
			if (str[i] != c)
				count++;
		}
		i++;
	}
	return (count);
}

size_t	ft_wordlen(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != c)
		i++;
	return (i);
}

char	*ft_strndup(const char *src, size_t	n)
{
	size_t	i;
	char	*dst;

	i = 0;
	dst = malloc(sizeof(char) * (n + 1));
	if (!dst)
		return (NULL);
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	size_t	j;
	size_t	size;
	char	**tab;

	size = ft_count_words(s, c);
	tab = malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	size = 0;
	j = 0;
	while (s[size])
	{
		tab[j] = ft_strndup(s, ft_wordlen(&s[size], c));
		if (!tab[j])
		{
			ft_free_tab(tab, size + 1);
			return (NULL);
		}
		size += ft_wordlen(&s[size], c);
		if (tab[j][0] != 0)
			j++;
		else
			free(tab[j]);
		size++;
	}
	tab[size] = NULL;
	return (tab);
}