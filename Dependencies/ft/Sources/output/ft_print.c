/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 06:08:28 by jzoltan           #+#    #+#             */
/*   Updated: 2022/02/09 10:31:29 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_print_flush_arg.h"
#include "detail_print.h"

static void	ft_print_do(va_list *args_list, int type)
{
	static void (*const	t[])(va_list *) = {
		0, ft_print_int, ft_print_str, ft_print_flush};

	t[type](args_list);
}

int	ft_print(int type, ...)
{
	va_list	args_list;

	va_start(args_list, type);
	if (ft_print_get_args()->error)
		return (0);
	while (ft_print_get_args()->lock)
		;
	ft_print_get_args()->lock = 1;
	while (type)
	{
		if (ft_print_get_args()->error)
		{
			ft_print_get_args()->lock = 1;
			return (0);
		}
		ft_print_do(&args_list, type);
		type = va_arg(args_list, int);
	}
	va_end(args_list);
	ft_print_get_args()->lock = 0;
	return (1);
}
