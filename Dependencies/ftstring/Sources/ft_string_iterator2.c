/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_iterator2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:13:41 by jzoltan           #+#    #+#             */
/*   Updated: 2022/02/04 10:13:42 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_string_iterator_index(t_ft_string_iterator const *iterator)
{
	return ((iterator->start_str)
		* iterator->string->app_size
		+ iterator->end_c
		- ((size_t)iterator->end - (size_t)iterator->it));
}
