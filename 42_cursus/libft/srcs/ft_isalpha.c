#include <ctype.h>
#include <stdio.h>

int	ft_isalpha(int c)
{
	if (c >= 65 && c <= 90)
		return (1024);
	if (c >= 97 && c <= 122)
		return (1024);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	printf("%d\n%d", ft_isalpha(argv[1][0]), isalpha(argv[1][0]));
	return (0);
}
