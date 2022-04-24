/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_cstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:55:33 by jzoltan           #+#    #+#             */
/*   Updated: 2022/02/03 12:55:33 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_string_cstr(t_ft_string string)
{
	char	*str;
	char	*it;
	size_t	i;
	size_t	j;

	str = malloc((string->cur_c + string->cur_str * string->app_size + 1)
			* sizeof(char));
	if (!str)
		return (0);
	it = str - 1;
	i = ~((size_t)(0));
	while (++i != string->cur_str)
	{
		j = ~((size_t)(0));
		while (++j != string->app_size)
			*++it = string->strs[i][j];
	}
	i = 0;
	while (i != string->cur_c)
	{
		*++it = string->strs[string->cur_str][i];
		++i;
	}
	*++it = 0;
	return (str);
}
