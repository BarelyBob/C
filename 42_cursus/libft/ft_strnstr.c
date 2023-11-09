/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:01:20 by mpitot            #+#    #+#             */
/*   Updated: 2023/11/09 16:18:06 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lsize;

	if (!big || !little)
		return (NULL);
	i = 0;
	lsize = ft_strlen(little);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			if (j == lsize)
				return (&((char *) big)[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
