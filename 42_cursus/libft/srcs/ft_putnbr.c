#include <unistd.h>

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
