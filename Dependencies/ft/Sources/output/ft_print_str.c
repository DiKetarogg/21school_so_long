/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:24:14 by jzoltan           #+#    #+#             */
/*   Updated: 2022/02/09 10:25:16 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "detail_print.h"

void	ft_print_str(va_list *args_list)
{
	char const	*str = va_arg(*args_list, char const *);
	char const	*end = ft_print_get_args()->end;
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
