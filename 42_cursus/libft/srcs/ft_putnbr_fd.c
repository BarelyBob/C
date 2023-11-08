/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:03:46 by mpitot            #+#    #+#             */
/*   Updated: 2023/11/08 14:06:18 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd_unsigned(unsigned int n, int fd)
{
	if (n < 10)
		ft_putchar_fd(n + 48, fd);
	else
	{
		ft_putnbr_fd_unsigned(n / 10, fd);
		ft_putchar_fd(n % 10, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd_unsigned(n * -1, fd);
	}
	else
		ft_putnbr_fd_unsigned(n, fd);
}