/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:20:18 by emuminov          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/10/01 16:17:53 by mpitot           ###   ########.fr       */
=======
/*   Updated: 2023/10/01 13:41:33 by emuminov         ###   ########.fr       */
>>>>>>> 1e44852d3c57dd7891473f1cc0e3441e4c4ccac7
/*                                                                            */
/* ************************************************************************** */

#include "libs.h"
#include "ft_split.c"
#include "utils2.h"

// TODO DELETE LATER
#include <stdio.h>
///////////////////////////////////////////
//!!! FILE CONTAINING DICT OPERATIONS !!!//
///////////////////////////////////////////

/*
CHECKLIST:
- [x] Make validations for the format of dictionary rows
- [x] Read the dictionary
- [x] Make validation for presence of 0-19 entries in the dict
- [x] Make validation for the entire dictionary
- [x] Convert each row in the correct data structure
- [x] Strip all the redundant spaces from the numeric_str and alpha_str
- [x] Fix the problem with garbage output from ft_strjoin
- [ ] Compare the number of digits of input against the number of digits in the biggest value.
- [ ] Handle the case when you can't open the file due to permissions or renaming.
- [ ] Pass split_dict to ft_valdict directly
- [ ] Display error in case of failure to parse the dictionary (due to renaming or changning permissions)
- [ ] Break the file into multiple ones, settle utils functions in utils*.c files
- [ ] Move library includes to header file
- [ ] Fix all possible leaks with valgrind
- [ ] Normalize all the files
- [ ] (??? optional) Make ft_check_num work with all numbers
*/

// Temporary struct with the pure read dict file and its size.
// Stores size of the read bytes from read and the contents of
// the file.
typedef struct s_raw_dict
{
	unsigned int	size;
	char			*str;
}			t_raw_dict;

// Temporary implementation of read.
// 1500 because I am not sure how to calculate precise
// filesize with functions allowed by the subject.
t_raw_dict	ft_read_dict(const char *dict_path)
{
	char			*str;
	unsigned int	size;
	int				fd;
	t_raw_dict		res;

	fd = open(dict_path, O_RDONLY);
	if (fd == -1)
	{
		res.size = 0;
		return (res);
	}
	res.str = malloc(sizeof(char) * 1500);
	if (res.str == 0)
	{
		res.size = 0;
		return (res);
	}
	res.size = read(fd, res.str, 1500);
	close(fd);
	return (res);
}
<<<<<<< HEAD

// TODO: move to utils
int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}


// TODO: move to utils
int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\f')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

int	ft_strslen(int size, char **strs)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (i < size)
	{
		l += ft_strlen(strs[i]);
		i++;
	}
	return (l);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	res_size;
	char	*res;

	if (size == 0)
	{
		res = malloc(sizeof(char) * 1);
		if (res == 0)
			return (0);
		res[0] = '\0';
		return (res);
	}
	res_size = (sizeof(char) * ft_strslen(size, strs)) + (sizeof(char) * (ft_strlen(sep) * (size - 1)) + 1);
	res = malloc(res_size);
	if (res == 0)
		return (0);
	i = 0;
	res[0] = '\0';
	while (strs[i])
	{
		ft_strcat(res, strs[i]);
		if (i < size - 1)
			ft_strcat(res, sep);
		i++;
	}
	return (res);
}

=======
>>>>>>> 1e44852d3c57dd7891473f1cc0e3441e4c4ccac7
// Used in ft_check_twenty.
// Checks if the number is present in the dict.
// WARNING: it uses atoy and does not
// go for the numbers too big.

int	ft_check_num(int n, char **split_dict)
{
	int		i;
	int		j;
	char	*s_nbr;
	int		nbr;

	i = 0;
	while (split_dict[i] != 0)
	{
		j = 0;
		while (ft_is_digit(split_dict[i][j]) && split_dict[i][j])
			j++;
		if (j < 9)
		{
			nbr = ft_atoi(split_dict[i]);
			if (nbr == n)
				return (1);
		}
		i++;
	}
	return (0);
}

// Checks if the 0-19 numbers are present in the dict.
int	ft_check_twenty(char **split_dict)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (!ft_check_num(i, split_dict))
			return (0);
		i++;
	}
	return (1);
}

// Used for cleaning after ft_split.
void	ft_freesplit(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
}

// Used in ft_valdict.
// Calculates if the specific row of the dict is valid.
int	ft_valdictrow(char *row)
{
	int	i;

	i = 0;
	if (!ft_is_digit(row[i]))
		return (0);
	while (ft_is_digit(row[i]))
		i++;
	while (row[i] == ' ')
		i++;
	if (row[i] != ':')
		return (0);
	while (row[i])
	{
		if (row[i] < 32 || row[i] == 127)
			return (0);
		i++;
	}
	return (1);
}

// Validates dictionary.
// The dictionary is valid if every row is
// [a number][0 to n spaces]:[0 to n spaces][any printable characters]
// It takes raw read dict and splits it by the \n.
int	ft_valdict(char *dict)
{
	int		i;
	char	**split_dict;

	split_dict = ft_split(dict, "\n");
	i = 0;
	while (split_dict[i] != 0)
	{
		if (!ft_valdictrow(split_dict[i]))
		{
			ft_freesplit(split_dict);
			free(split_dict);
			return (0);
		}
		i++;
	}
	if (!ft_check_twenty(split_dict))
	{
		ft_freesplit(split_dict);
		free(split_dict);
		return (0);
	}
	ft_freesplit(split_dict);
	free(split_dict);
	return (1);
}

// Removes character from string.
// Used in ft_row_to_entry for removing whitespaces
// from numeric_str.
char	*ft_remove_char(char c, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			j = i;
			while (str[j])
			{
				str[j] = str[j + 1];
				j++;
			}
			i--;
		}
		i++;
	}
	return (str);
}

// numeric_str = 10
// alpha_str = ten
// numeric_str holds the sential value. If it's NULL
// then it's the end of an array.
typedef struct s_dict_entry
{
	char	*numeric_str;
	char	*alpha_str;
}		t_dict_entry;

// Counts the number of NULL-pointer terminated
// arrays of characters.
int	ft_tablen(char **strs)
{
	int	l;

	l = 0;
	while (strs[l])
		l++;
	return (l);
}

// Used in ft_row_to_entry.
// Strips alphabetic portion of entry from redundant spaces.
// ("   hey   everybody !" -> "hey everybody !")
// Just like in the example in the subject.
char	*ft_process_raw_alpha_string(char *raw)
{
	char	*res;
	char	**split_raw;
	int		split_size;
	int		i;

	split_raw = ft_split(raw, " ");
	split_size = ft_tablen(split_raw);
	res = ft_strjoin(split_size, split_raw, " ");
	i = 0;
	while (i < split_size)
	{
		free(split_raw[split_size]);
		i++;
	}
	free(split_raw);
	return (res);
}

// Converts valid row in the dict to s_dict_entry structure.
// Uses ft_split, needs to be freed accordingly.
// Splits the row by ":". Removes whitespaces from numeric_str
// and redunant spaces from alpha_str.
t_dict_entry	ft_row_to_entry(char *row)
{
	t_dict_entry	res;
	char			*raw_numeric_str;
	char			*raw_alpha_str;
	char			**split_row;

	split_row = ft_split(row, ":");
	raw_numeric_str = split_row[0];
	raw_alpha_str = split_row[1];
	res.numeric_str = ft_remove_char(' ', raw_numeric_str);
	res.alpha_str = ft_process_raw_alpha_string(raw_alpha_str);
	free(split_row);
	return (res);
}

// Iterates over an array of of dict rows and
// converts them all to s_dict_entry, and adds
// to the tab. Sentiel value is stored in numeric_str.
t_dict_entry	*ft_dict_to_tab(char **split_dict)
{
	int				i;
	int				j;
	int				l;
	t_dict_entry	*tab;

	i = 0;
	j = 0;
	l = ft_tablen(split_dict);
	tab = malloc(sizeof(t_dict_entry) * l + sizeof((void *)0));
	if (tab == NULL)
		return (NULL);
	while (split_dict[i])
	{
		tab[i] = ft_row_to_entry(split_dict[i]);
		i++;
	}
	tab[i].numeric_str = NULL;
	return (tab);
}

/*
int	main(void)
{
	t_raw_dict			dict;
	int					i;
	char				**split_dict;
	t_dict_entry		*tab;

	dict = ft_read_dict("numbers.dict");
	split_dict = ft_split(dict.str, "\n");
	i = 0;
	if (ft_valdict(dict.str))
		printf("Dict is valid\n");
	else
		printf("Unvalid dict\n");
	tab = ft_dict_to_tab(split_dict);
	ft_freesplit(split_dict);
	free(dict.str);
	free(split_dict);
	i = 0;
	while (tab[i].numeric_str)
	{
		printf("numeric %s:alpha %s\n", tab[i].numeric_str, tab[i].alpha_str);
		i++;
	}
	i = 0;
	while (tab[i].numeric_str)
	{
		free(tab[i].numeric_str);
		free(tab[i].alpha_str);
		i++;
	}
	free(tab);
}
*/
