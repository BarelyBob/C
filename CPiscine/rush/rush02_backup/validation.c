/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:46:24 by emuminov          #+#    #+#             */
/*   Updated: 2023/10/01 13:53:20 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

// validates the number argument
int	ft_valarg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

// TODO: create validation for the dictionary
int	ft_valdict(char *dict)
{
	int	i;

	i = 0;
	if (dict[i])
		return (1);
	return (0);
}

// validates input of main
int	ft_valinput(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		return (0);
	if ((argc == 2 && !ft_valarg(argv[1]))
		|| (argc == 3 && (!ft_valdict(argv[1]) || !ft_valarg(argv[2]))))
		return (0);
	return (1);
}
