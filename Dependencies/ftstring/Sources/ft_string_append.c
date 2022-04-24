/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:53:45 by jzoltan           #+#    #+#             */
/*   Updated: 2022/02/03 12:53:51 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <unistd.h>

int	ft_string_append_char(t_ft_string string, char c)
{
	if (!ft_string_detail_add_str(string))
		return (0);
	string->strs[string->cur_str][string->cur_c] = c;
	++string->cur_c;
	return (1);
}

int	ft_string_append_str(t_ft_string string, char const *str)
{
	char			*it;
	size_t			i;
	size_t const	app_size = string->app_size;

	while (*str)
	{
		if (!ft_string_detail_add_str(string))
			return (0);
		i = string->cur_c;
		it = string->strs[string->cur_str];
		while (*str && i != app_size)
		{
			it[i] = *str;
			++i;
			++str;
		}
		string->cur_c = i;
	}
	return (1);
}

int	ft_string_append_fd(t_ft_string string, int fd)
{
	int	r;

	if (!ft_string_detail_add_str(string))
		return (0);
	r = read(fd, &string->strs[string->cur_str][string->cur_c],
			string->app_size - string->cur_c);
	while (r)
	{
		if (r < 0)
			return (0);
		string->cur_c += r;
		if (!ft_string_detail_add_str(string))
			return (0);
		r = read(fd, string->strs[string->cur_str], string->app_size);
	}
	return (1);
}
