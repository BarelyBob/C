/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:58:55 by mpitot            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/10/01 15:55:28 by mpitot           ###   ########.fr       */
=======
/*   Updated: 2023/10/01 07:14:27 by emuminov         ###   ########.fr       */
>>>>>>> 1e44852d3c57dd7891473f1cc0e3441e4c4ccac7
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "dict.h"
#include "utils2.h"
#include <stdio.h>

void	ft_putchar(char c);

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != 0 || s2[i] != 0)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

void	ft_fill_tab(char **tab, int size, char *str)
{
	int	j;
	int	k;

	j = ft_strlen(str) - 1;
	while (size >= 0 && j >= 0)
	{
		k = 2;
		tab[size] = malloc(sizeof(char) * 4);
		while (k >= 0 && j >= 0)
		{
			tab[size][k] = str[j];
			//else 
				//tab[size][k] = '#';
			k--;
			j--;
		}
		while  (k >= 0)
		{
			tab[size][k] = '#';
			k--;
		}
		tab[size][3] = 0;
		size--;
	}
}

int	ft_getsize(char *str)
{
	int	size;

	size = ft_strlen(str);
	if (size % 3 == 0)
		size /= 3;
	else
		size = (size / 3) + 1;
	return (size);
}

char	**ft_substr(char *str, int size)
{
	char	**tab;

	tab = malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	ft_fill_tab(tab, size - 1, str);
	tab[size] = NULL;
	return (tab);
}

void	ft_hundred(char *str, t_dict_entry *tab)
{
	int	i;
	char	nb;

	nb = str[0];
	str[0] = '#';
	i = 0;
	if (nb == '0')
		return ;
	while (tab[i].numeric_str)
	{
		if (nb == tab[i].numeric_str[0])
		{
			ft_putstr(tab[i].alpha_str);
			ft_putchar(' ');
			break;
		}
		i++;
	}
	i = 0;
	while (tab[i].numeric_str)
	{
		if (ft_strcmp(tab[i].numeric_str, "100") == 0)
		{
			ft_putstr(tab[i].alpha_str);
			ft_putchar(' ');
			break;
		}
		i++;
	}
}

void	ft_ten(char *str, t_dict_entry *tab)
{
	int	i;
	char	nb[2];

	if (str[0] == '1')
	{
		nb[0] = '1';
		nb[1] = str[1];
		str[0] = '#';
		str[1] = '#';
	}
	else
	{
		nb[0] = str[0];
		nb[1] = '0';
		str[0] = '#';
		if (str[1] == '0')
			str[1] = '#';
	}
	i = 0;
	while (tab[i].numeric_str)
	{
		if (nb[0] == tab[i].numeric_str[0] && nb[1] == tab[i].numeric_str[1])
		{
			ft_putstr(tab[i].alpha_str);
			ft_putchar(' ');
			break;
		}
		i++;
	}
}

void	ft_units(char *str, t_dict_entry *tab)
{
	int	i;
	char	nb;

	nb = str[0];
	str[0] = '#';
	i = 0;
	while (tab[i].numeric_str)
	{
		if (nb == tab[i].numeric_str[0])
		{
			ft_putstr(tab[i].alpha_str);
			ft_putchar(' ');
			break;
		}
		i++;
	}
}

void	write_block(char *str, t_dict_entry *dict)
{
	int	i;
	
	i = 0;
	while (i < 3)
	{
		if (str[i] != '#')
		{
			if (i == 0)
				ft_hundred(str, dict);
		   	else if (i == 1)
				ft_ten(&str[i], dict);
			else if (i == 2)
				ft_units(&str[i], dict);
		}
		i++;
	}
}

/*void	check_power(char *nbr, t_dict_entry *tab)
{
	int	k;
	int	i;

	i = 0;
	while (tab[i].numeric_str)
	{
		k = 0;
		while (tab[i].numeric_str && nbr[k] && tab[i].numeric_str[k] == nbr[k])
			k++;
		if (nbr[k] == tab[i].numeric_str[k])
  		{
	  		ft_putstr(tab[i].alpha_str);
  			ft_putchar(' ');
  			return ;
  		}
  		i++;
	}
}
*/
void	write_multiple(char *power, t_dict_entry *dict)
{
	int	i;

	i = 0;
	while (dict[i].numeric_str)
	{
		if (ft_strcmp(dict[i].numeric_str, power) == 0)
		{
			ft_putstr(dict[i].alpha_str);
			ft_putchar(' ');
			break ;
		}
		i++;
	}
}

char	*ft_power_creator(int size)
{
	char	*power;
	int	nsize;
	int	i;

	nsize = 3 * (size - 1) + 2;
	power = malloc(sizeof(char) * nsize);
	i = 0;
	while (i < nsize)
	{
		if (i == 0)
			power[i] = '1';
		else
			power[i] = '0';
		i++;
	}
	power[nsize - 1] = 0;
	return (power);
}

void	ft_print_all(char *str, t_dict_entry *dict)
{
	char	**tab;
	char	*power;
	int	size;
	int	i;
	int	status;

	size = ft_getsize(str);
	//printf("%d", size);
	tab = ft_substr(str, size);
	i = 0;
	while (size > 0)
	{
		status = ft_strcmp(tab[i], "000");
		write_block(tab[i], dict);
		if (size > 1 && status != 0)
		{
			power = ft_power_creator(size);
			write_multiple(power, dict);
		}
		size--;
		i++;
	}
<<<<<<< HEAD
}
=======
	return ("Error");
}*/
>>>>>>> 1e44852d3c57dd7891473f1cc0e3441e4c4ccac7

#include <stdio.h>

int     main(int argc, char **argv)
{
	int i = 0;
	char **tab;
	t_raw_dict raw_dict;
	char **split_dict;
	t_dict_entry *dict;

	if (argc != 2)
		return (1);
	//tab = ft_substr(argv[1]);
	raw_dict = ft_read_dict("numbers.dict");
	split_dict = ft_split(raw_dict.str, "\n");
	dict = ft_dict_to_tab(split_dict);
	ft_print_all(argv[1], dict);
}

	/*while (dict[i].numeric_str)
	{
		printf("ALPHA %s : NUMERIC %s\n", dict[i].alpha_str, dict[i].numeric_str);
		i++;
	}*/

