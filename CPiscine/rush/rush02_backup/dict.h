/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpitot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 09:42:38 by mpitot            #+#    #+#             */
/*   Updated: 2023/10/01 09:59:20 by mpitot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
#define DICT_H
typedef struct	s_raw_dict
{
	unsigned int	size;
	char		*str;
}			t_raw_dict;

typedef struct	s_dict_entry
{
	char *numeric_str;
	char *alpha_str;
}		t_dict_entry;

t_dict_entry	*ft_dict_to_tab(char **split_dict);

t_raw_dict	ft_read_dict(const char* dict_path);

int		ft_valdict(char *dict);

void		ft_freesplit(char **split);
#endif
