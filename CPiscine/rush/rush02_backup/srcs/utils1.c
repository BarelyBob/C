/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:47:53 by emuminov          #+#    #+#             */
<<<<<<< HEAD:utils.c
/*   Updated: 2023/10/01 09:54:29 by mpitot           ###   ########.fr       */
=======
/*   Updated: 2023/10/01 11:47:04 by emuminov         ###   ########.fr       */
>>>>>>> 1e44852d3c57dd7891473f1cc0e3441e4c4ccac7:srcs/utils1.c
/*                                                                            */
/* ************************************************************************** */

#include "libs.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

<<<<<<< HEAD:utils.c
int	ft_strlen(char *str)
{
	int	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
=======
int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\f')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
>>>>>>> 1e44852d3c57dd7891473f1cc0e3441e4c4ccac7:srcs/utils1.c
}
