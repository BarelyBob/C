/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:53:24 by mpitot            #+#    #+#             */
/*   Updated: 2023/11/09 09:53:51 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int 	ft_contains(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	size;
	char	*new;

	i = 0;
	size = ft_strlen(s1);
	while (ft_contains(set, s1[i]))
		i++;
	size -= i;
	while (ft_contains(set, s1[size - 1]))
		size--;
	new = ft_substr(s1, i, size);
	if (!new)
		return (NULL);
	return (new);
}
