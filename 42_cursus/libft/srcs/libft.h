/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:27:53 by mpitot            #+#    #+#             */
/*   Updated: 2023/11/07 13:38:58 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);

void	ft_putchar(char c);
void	ft_putendl(const char *s);
void	ft_putnbr(int n);
void	ft_putstr(char const *s);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));

int		ft_atoi(const char *nptr);
int		ft_isalpha(int c);
