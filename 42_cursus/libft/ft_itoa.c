/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:33:08 by mpitot            #+#    #+#             */
/*   Updated: 2023/11/09 16:20:39 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_getsize(int n)
{
	size_t	count;

	count = 1;
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_fill(int n, size_t len, int sign)
{
	size_t	stop;
	char	*str;

	str = malloc(sizeof(char) * (len + 1));
	ft_memset(str, 0, len + 1);
	if (!str)
		return (NULL);
	stop = 0;
	if (sign == -1)
	{
		str[0] = '-';
		stop++;
	}
	while (len > stop)
	{
		str[len] = n % 10;
		n = n / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		sign;
	size_t	len;
	char	*str;

	sign = 1;
	len = ft_getsize(n);
	if (n < 0)
	{
		sign = -1;
		n *= -1;
		len++;
	}
	str = ft_fill(n, len, sign);
	if (!str)
		return (NULL);
	return (str);
}
