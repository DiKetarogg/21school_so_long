/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_get_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 09:29:49 by jzoltan           #+#    #+#             */
/*   Updated: 2022/02/09 10:25:55 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "detail_types.h"

t_args	ft_print_get_args(void)
{
	static struct s_args	args = {.end = args.buffer + FT_BUFFER_SIZE,
		.it = args.buffer, .lock = 0, .error = 0};

	return (&args);
}
