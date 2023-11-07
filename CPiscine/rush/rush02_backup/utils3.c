/* ************************************************************************** */
/*	                                                                       */
/*	                                                   :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*	                                               +:+ +:+         +:+     */
/*   By: mpitot <marvin@42.fr>	                 +#+  +:+       +#+        */
/*	                                           +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:02:05 by mpitot	       #+#    #+#             */
/*   Updated: 2023/09/28 17:55:56 by mpitot           ###   ########.fr       */
/*	                                                                       */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_contains(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_words_amount(char *str, char *charset)
{
	int	i;
	int	count;
	int	state;

	i = 0;
	count = 0;
	state = 0;
	while (str[i])
	{
		if (ft_contains(str[i], charset) == 1 && state == 1)
			state = 0;
		else if (ft_contains(str[i], charset) == 0 && state == 0)
		{
			state = 1;
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_wordlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (ft_contains(str[i], charset) == 0 && str[i])
		i++;
	return (i);
}

char	*ft_strndup(char *src, int n)
{
	int		i;
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

char	**ft_split(char *str, char *charset)
{
	int		size;
	int		i;
	int		j;
	char	**tab;

	size = ft_words_amount(str, charset);
	tab = malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		tab[j] = ft_strndup(&str[i], ft_wordlen(&str[i], charset));
		i += ft_wordlen(&str[i], charset);
		if (tab[j][0] != 0)
			j++;
		i++;
	}
	tab[size] = 0;
	return (tab);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	int	i;
	char	**tab;
	if (argc != 3)
		return (1);
	tab = ft_split(argv[1], argv[2]);
	for (i = 0; i < ft_words_amount(argv[1], argv[2]); i++)
		printf("%s\n", tab[i]);
	return (0);
}*/
