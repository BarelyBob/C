/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <mpitot@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:27:53 by mpitot            #+#    #+#             */
/*   Updated: 2023/11/07 20:22:07 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#ifndef LIBFT_H
# define LIBFT_H

size_t	ft_strlen(const char *s);

void	ft_putchar(char c);
void	ft_putendl(const char *s);
void	ft_putnbr(int n);
void	ft_putstr(char const *s);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);

char	*ft_strjoin(const char *s1, const char *s2);

int		ft_atoi(const char *nptr);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

#endif
