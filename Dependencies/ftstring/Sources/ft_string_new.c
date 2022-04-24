/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:53:17 by jzoltan           #+#    #+#             */
/*   Updated: 2022/02/03 12:53:32 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_ft_string	ft_string_new(size_t app_size)
{
	t_ft_string	string;

	if (!app_size)
		return (0);
	string = malloc(sizeof(struct s_ft_string));
	if (!string)
		return (0);
	string->strs = malloc(sizeof(char *) * 16);
	if (!string->strs)
	{
		free(string);
		return (0);
	}
	*string->strs = 0;
	string->strings_count = 0;
	string->cur_str = 0;
	string->cur_c = 0;
	string->strs_size = 16;
	*(size_t *)&string->app_size = app_size;
	return (string);
}
