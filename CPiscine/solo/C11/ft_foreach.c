/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:00:36 by mpitot            #+#    #+#             */
/*   Updated: 2023/10/05 10:21:46 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void(*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
		(*f)(tab[i++]);
}

void	ft_putnbr(int	:q
		:wq


int	main(void)
{
	int	tab[] = {5, 8, 2, 4, 8, 7, 4, 9};

	ft_foreach(tab, 8, &ft_putnbr);
	return (0);
}
