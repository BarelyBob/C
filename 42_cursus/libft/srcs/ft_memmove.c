/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:20:37 by mpitot            #+#    #+#             */
/*   Updated: 2023/11/08 16:24:54 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src < dest)
	{
		while (n-- > 0)
		{
			((unsigned char *) dest)[i] = ((unsigned char *) src)[n];
			i++;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}