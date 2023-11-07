/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 09:46:32 by mpitot            #+#    #+#             */
/*   Updated: 2023/10/01 09:58:37 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_contains(char c, char *charset);

char	*ft_strndup(char *src, int n);

char	**ft_split(char *str, char *charset);

int	ft_strlen(char *str);

void	ft_putstr(char *str);
