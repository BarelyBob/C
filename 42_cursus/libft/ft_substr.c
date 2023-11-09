/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:03:01 by mpitot            #+#    #+#             */
/*   Updated: 2023/11/09 16:18:06 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s || len == 0)
		return (NULL);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = start;
	while (i < len && s[i])
	{
		new[i] = s[start];
		i++;
		start++;
	}
	return (new);
}
