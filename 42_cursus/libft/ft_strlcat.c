/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:01:59 by mpitot            #+#    #+#             */
/*   Updated: 2023/11/13 11:58:56 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	sz;

	i = 0;
	j = ft_strlen(dst);
	while (src[i] && i < size - 1)
	{
		dst[i + j] = src[i];
		i++;
	}
	dst[i + j] = '\0';
	sz = ft_strlen(src);
	return (j + sz);
}

/*int	main(int argc, char **argv)
{
	(void) argc;
	char *str;
	int n;

	n = ft_strlcat

	printf("%s", ft_strlcat)
}*/