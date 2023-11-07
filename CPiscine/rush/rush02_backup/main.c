/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:12:47 by mpitot            #+#    #+#             */
/*   Updated: 2023/10/01 13:59:05 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "validation.h"

int main(int argc, char **argv)
{
	if (!ft_valinput(argc, argv))
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (argc == 2)
		printf("%d\n", ft_valarg(argv[1]));
	if (argc == 3)
		printf("%d\n", ft_valarg(argv[2]));
	return (0); 
}
