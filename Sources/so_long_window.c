/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:31:38 by jzoltan           #+#    #+#             */
/*   Updated: 2022/03/28 06:31:10 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>
#include <stdlib.h>
#include <ft.h>

void	so_long_clear_pos(t_so_long so_long, int x, int y)
{
	so_long_replace_image(so_long, so_long->img_map[y][x],
		x * 32, (y + 1) * 32);
	if (so_long->map.data[y][x] & 2)
		so_long_put_filler(so_long, so_long->tiles[0],
			x * 32, (y + 1) * 32);
}

void	so_long_put_pos(t_so_long so_long, void *img, int x, int y)
{
	so_long_put_image(so_long, img, x * 32, (y + 1) * 32);
}

void	so_long_put_pos_32(t_so_long so_long, void *img, int x, int y)
{
	so_long_put_image(so_long, img, x, (y + 32));
}

int	so_long_flush_screen(t_so_long so_long)
{
	return (mlx_put_image_to_window(so_long->mlx, so_long->window,
			so_long->img_buff,
			-so_long->player.x * 32 + 360, -so_long->player.y * 32 + 240));
}
