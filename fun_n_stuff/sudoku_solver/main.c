#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	ft_get_size(char *file_path)
{
	int	fd;
	int	sz;
	int	count;
	char	tmp[90];

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	sz = 1;
	while (sz > 0)
	{
		sz = read(fd, tmp, 89);
		count += sz;
	}
	close(fd);
	return (count);
}

char	*ft_read_file(char *file_path)
{
	int	fd;
	int	sz;
	char	*str;

	sz = ft_get_size(file_path);
	if (sz == -1)
		return (NULL);
	str = malloc(sizeof(char) * (sz +1));
	if (!str)
		return (NULL);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	sz = read(fd, str, sz);
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_realloc(char *str, int n)
{
	int	size;
	int	i;
	char	*new;

	size = ft_strlen(str);
	new = malloc(sizeof(char) * (size + n));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

int	ft_is_finished(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 1] == '\n' && str[len - 2] == '\n')
		return (1);
	return (0);
}

char	*ft_read_entry(void)
{
	int	sz;
	char	*str;
	
	sz = 1;
	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	while (sz > 0)
	{
		sz = read(0, str, 1);
		if (ft_is_finished(str) == 1)
			break ;
		str = ft_realloc(str, sz);
		if (!str)
			return (NULL);
	}
	return (str);
}
#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc != 1)
		return (1);
	//char	*str = ft_read_file(argv[1]);
	char	*str = ft_read_entry();
	(void)argv;
	printf("%s", str);
	return (0);
}
