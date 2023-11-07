/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:03:56 by emuminov          #+#    #+#             */
/*   Updated: 2023/10/01 16:22:10 by aolsen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
int		ft_is_digit(char c);
int		ft_atoi(char *str);
int		ft_strslen(int size, char **strs);
int		ft_strlen(char *str);
int		ft_contains(char c, char *charset);
void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_strcat(char *dest, char *src);
char	*ft_strjoin(int size, char **strs, char *sep);
char	*ft_strndup(char *src, int n);
char	**ft_split(char *str, char *charset);
#endif
