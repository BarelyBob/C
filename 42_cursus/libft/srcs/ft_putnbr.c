/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:31:46 by mpitot            #+#    #+#             */
/*   Updated: 2023/11/08 17:30:03 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_unsigned(unsigned int n)
{
	if (n < 10)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr_unsigned(n / 10);
		ft_putchar(n % 10);
	}
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr_unsigned(n * -1);
	}
	else
		ft_putnbr_unsigned(n);
}
