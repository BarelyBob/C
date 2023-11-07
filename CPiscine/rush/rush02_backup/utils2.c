/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:47:58 by emuminov          #+#    #+#             */
/*   Updated: 2023/10/01 13:58:31 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
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

char	*concat_everything(char *res, int size, char **strs, char *sep)
{
	int	i;

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

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		str_size;
	int		sep_size;
	char	*res;

	if (size == 0)
	{
		res = malloc(sizeof(char) * 1);
		if (res == 0)
			return (0);
		res[0] = '\0';
		return (res);
	}
	str_size = (sizeof(char) * ft_strslen(size, strs) + 1);
	sep_size = (sizeof(char) * (ft_strlen(sep) * (size - 1)));
	res = malloc(str_size + sep_size);
	if (res == 0)
		return (0);
	concat_everything(&res, size, strs, sep);
	return (res);
}
