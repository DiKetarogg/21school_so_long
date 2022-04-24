/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detail.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:53:54 by jzoltan           #+#    #+#             */
/*   Updated: 2022/02/03 12:57:41 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static int	ft_string_detail_add_str_internal(t_ft_string string)
{
	char	**strs;
	size_t	i;

	if (string->strings_count == string->strs_size)
	{
		strs = malloc(sizeof(char *) * (string->strs_size * 2));
		if (!strs)
			return (0);
		string->strs_size *= 2;
		i = 0;
		while (i != string->strings_count)
		{
			strs[i] = string->strs[i];
			++i;
		}
		free(string->strs);
		string->strs = strs;
	}
	string->strs[string->strings_count] = (char *){
		malloc(string->app_size * sizeof(char))};
	if (!string->strs[string->strings_count])
		return (0);
	++string->strings_count;
	return (1);
}

int	ft_string_detail_add_str(t_ft_string string)
{
	if (string->cur_c == string->app_size)
	{
		++string->cur_str;
		string->cur_c = 0;
	}
	if (string->strings_count == string->cur_str)
	{
		if (!ft_string_detail_add_str_internal(string))
			return (0);
	}
	return (1);
}
