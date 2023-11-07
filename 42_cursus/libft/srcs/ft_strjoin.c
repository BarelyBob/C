char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*nstr;
	size_t	size;
	unsigned int	i;
	unsigned int	j;

	
	size = ft_strlen(s1) + ft_strlen(s2);
	nstr = malloc(sizeof(char) * (size + 1));
	i = 0;
	while (s1[i])
		nstr[i] = s1[i++];
	j = 0;
	while (s2[j])
		nstr[i++] = s2[j++];
	nstr[i] = '\0';
	return (nstr);
}
