void	ft_striter(char *s, void (*f)(char *))
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(&s[i]);
		i++;
	}
}
