/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 07:03:37 by jzoltan           #+#    #+#             */
/*   Updated: 2022/02/09 10:31:59 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "detail_print.h"

void	ft_print_save(char const *str)
{
	char *const	end = ft_print_get_args()->end;
	char		*it;

	it = ft_print_get_args()->it;
	while (*str)
	{
		if (it == end)
		{
			ft_print_get_args()->it = it;
			ft_print_flush();
			if (ft_print_get_args()->error)
				return ;
			it = ft_print_get_args()->it;
		}
		*it = *str;
		++str;
		++it;
	}
	ft_print_get_args()->it = it;
}
