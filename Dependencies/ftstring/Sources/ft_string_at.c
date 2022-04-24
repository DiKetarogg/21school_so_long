/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:13:50 by jzoltan           #+#    #+#             */
/*   Updated: 2022/02/04 10:13:51 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_string_last(t_ft_string string)
{
	if (string->cur_c)
		return (string->strs[string->cur_str][string->cur_c - 1]);
	if (string->cur_str)
		return (string->strs[string->cur_str - 1][string->app_size - 1]);
	return (0);
}
