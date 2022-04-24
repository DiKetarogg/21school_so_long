/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:54:48 by jzoltan           #+#    #+#             */
/*   Updated: 2022/02/04 10:12:48 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdlib.h>

struct s_ft_string
{
	char			**strs;
	size_t			strings_count;
	size_t			cur_str;
	size_t			cur_c;
	size_t const	app_size;
	size_t			strs_size;
};

typedef struct s_ft_string			*t_ft_string;

struct s_ft_string_iterator
{
	t_ft_string		string;
	char			*it;
	char			*end;
	size_t const	start_str;
	size_t const	start_c;
	size_t const	end_c;
};

typedef struct s_ft_string_iterator	t_ft_string_iterator;

t_ft_string				ft_string_new(size_t app_size);

void					ft_string_delete(t_ft_string string);

int						ft_string_detail_add_str(t_ft_string string);

int						ft_string_append_char(t_ft_string string, char c);
int						ft_string_append_str(t_ft_string string,
							char const *str);
int						ft_string_append_fd(t_ft_string string, int fd);

char					*ft_string_cstr(t_ft_string string);

int						ft_string_begin(t_ft_string string,
							t_ft_string_iterator *iterator);
int						ft_string_next_iterator(
							t_ft_string_iterator *iterator);
int						ft_string_make_iterator(t_ft_string string,
							t_ft_string_iterator *iterator, size_t start);
void					ft_string_iterator_copy(t_ft_string_iterator *dest,
							t_ft_string_iterator const *src);

size_t					ft_string_iterator_index(t_ft_string_iterator const
							*iterator);

size_t					ft_string_size(t_ft_string string);

int						ft_string_last(t_ft_string string);

#endif
