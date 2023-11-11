/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:33:08 by mpitot            #+#    #+#             */
/*   Updated: 2023/11/11 18:07:38 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count(int n)
{
	size_t	i;

	i = 0;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa_unsigned(unsigned int n, int fd, char *str)
{
	if (n < 10)
		str[0] = n + 48;
	else
	{
		str = ft_itoa_unsigned(n / 10, fd, str);
		str[0] = n % 10 + 48;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;

	str = malloc(sizeof(char) * (ft_count(n) + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		str = ft_itoa_unsigned(n * -1, -1, str);
	else
		str = ft_itoa_unsigned(n, 1, str);
	return (str);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	(void) argc;
	printf("%s", ft_itoa(atoi(argv[1])));
}