/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:09:34 by mpitot            #+#    #+#             */
/*   Updated: 2023/11/09 16:53:16 by mpitot           ###   ########.fr       */
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

char	**ft_fill_tab(char const *s, char c, char **tab)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			tab[j] = malloc(sizeof(char) * (ft_wordlen(&s[i], c)));
			if (!tab[j])
			{
				ft_free_tab(tab, i + 1);
				return (NULL);
			}
			ft_strlcpy(tab[j], s, ft_wordlen(&s[i], c));
			i += ft_wordlen(&s[i], c);
			j++;
		}
		else
			i++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	size_t	size;
	char	**tab;

	size = ft_count_words(s, c);
	tab = malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	tab = ft_fill_tab(s, c, tab);
	if (!tab)
		return (NULL);
	tab[size] = NULL;
	return (tab);
}
