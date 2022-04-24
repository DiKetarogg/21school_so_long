/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:56:57 by jzoltan           #+#    #+#             */
/*   Updated: 2022/02/03 12:56:58 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	ft_string_delete(t_ft_string string)
{
	size_t	i;

	i = 0;
	while (i != string->strings_count)
	{
		free(string->strs[i]);
		++i;
	}
	free(string->strs);
	free(string);
}
