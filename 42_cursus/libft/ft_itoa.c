/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:33:08 by mpitot            #+#    #+#             */
/*   Updated: 2023/11/10 12:02:30 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_revstr(char *str)
{
	size_t	i;
	size_t	j;
	char	temp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}

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
	if (!str)
		return (NULL);
	stop = 0;
	while (len > stop)
	{
		str[stop] = ((n % 10) + 48);
		n = n / 10;
		stop++;
	}
	if (sign == -1)
	{
		str[stop] = '-';
		stop++;
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
	str = ft_revstr(str);
	return (str);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	(void) argc;
	printf("%s", ft_itoa(atoi(argv[1])));
	return (0);
}