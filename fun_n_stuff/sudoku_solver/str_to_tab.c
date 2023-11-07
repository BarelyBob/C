int	**ft_str_to_tab(char *str)
{
	int	i;
	int	j;
	int	k;
	int	**tab;

	tab = malloc(sizeof(int *) * 9);
	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			j++;
			k = 0;
			tab[j] = malloc(sizeof(int) * 9);
		}
		else
			tab[j][k++] = str[i] - 48;
		i++;
	}

