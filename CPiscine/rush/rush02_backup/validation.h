/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuminov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:52:01 by emuminov          #+#    #+#             */
/*   Updated: 2023/09/30 13:55:20 by emuminov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
#define VALIDATION_H
# include <unistd.h>

int     ft_valarg(char *str);
int     ft_valdict(char *dict);
int	    ft_valinput(int argc, char **argv);

#endif
