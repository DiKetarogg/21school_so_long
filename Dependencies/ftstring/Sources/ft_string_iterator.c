/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_iterator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:14:28 by jzoltan           #+#    #+#             */
/*   Updated: 2022/02/04 10:14:29 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_string_begin(t_ft_string string, t_ft_string_iterator *iterator)
{
	if (!string->cur_str && !string->cur_c)
		return (0);
	iterator->string = string;
	iterator->it = string->strs[0];
	if (!string->cur_str)
	{
		*(size_t *)&iterator->end_c = string->cur_c;
		iterator->end = &string->strs[0][string->cur_c];
	}
	else
	{
		*(size_t *)&iterator->end_c = string->app_size;
		iterator->end = &string->strs[0][string->app_size];
	}
	*(size_t *)&iterator->start_c = 0;
	*(size_t *)&iterator->start_str = 0;
	return (1);
}

int	ft_string_make_iterator(t_ft_string string,
		t_ft_string_iterator *iterator, size_t start)
{
	size_t const			start_str = start / string->app_size;
	size_t const			start_c = start % string->app_size;
	size_t					end_c;

	if (start_str > string->cur_str)
		return (0);
	if (start_str == string->cur_str)
		end_c = string->cur_c;
	else
		end_c = string->app_size;
	iterator->string = string;
	iterator->it = &string->strs[start_str][start_c];
	iterator->end = &string->strs[start_str][end_c];
	*(size_t *)&iterator->start_str = start_str;
	*(size_t *)&iterator->start_c = start_c;
	*(size_t *)&iterator->end_c = end_c;
	return (1);
}

int	ft_string_next_iterator(t_ft_string_iterator *iterator)
{
	t_ft_string	string;

	if ((iterator->it + 1) < iterator->end)
	{
		++iterator->it;
		return (1);
	}
	string = iterator->string;
	if (iterator->start_str >= string->cur_str)
		return (0);
	ft_string_make_iterator(string, iterator, iterator->end_c
		+ iterator->start_str * string->app_size);
	return (iterator->it != 0);
}

void	ft_string_iterator_copy(t_ft_string_iterator *dest,
	t_ft_string_iterator const *src)
{
	dest->string = src->string;
	dest->it = src->it;
	dest->end = src->end;
	*(size_t *)&dest->start_str = src->start_str;
	*(size_t *)&dest->start_c = src->start_c;
	*(size_t *)&dest->end_c = src->end_c;
}
