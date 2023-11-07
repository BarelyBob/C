/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:27:45 by mpitot            #+#    #+#             */
/*   Updated: 2023/10/05 16:44:12 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int 	ft_any(char **tab, int(*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if ((*f)(tab[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
/*
int	ft_str_has_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == ' ')
			return (1);
	}
	return (0);
}
#include <stdio.h>
int	main(int argc, char **argv)
{
	argc += 0;
	printf("%d", ft_any(argv, &ft_str_has_space));
	return (0);
}*/
