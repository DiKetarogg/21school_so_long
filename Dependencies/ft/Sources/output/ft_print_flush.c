/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flush.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 07:03:48 by jzoltan           #+#    #+#             */
/*   Updated: 2022/02/09 10:34:35 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "detail_print.h"
#include <unistd.h>

void	ft_print_flush(void)
{
	t_args	args;

	args = ft_print_get_args();
	args->error = write(STDOUT_FILENO,
			args->buffer, (size_t)args->it - (size_t)args->buffer) < 0;
	args->it = args->buffer;
}

int	ft_flush(void)
{
	ft_print_flush();
	return (ft_print_get_args()->error);
}
