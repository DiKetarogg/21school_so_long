/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:31:30 by jzoltan           #+#    #+#             */
/*   Updated: 2022/02/09 14:49:54 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int	so_long_loop(t_so_long so_long)
{
	return (mlx_loop(so_long->mlx));
}