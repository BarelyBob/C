#include <unistd.h>

void	ft_putstr(char const *s)
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}
