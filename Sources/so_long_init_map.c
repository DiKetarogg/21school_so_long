/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:47:06 by jzoltan           #+#    #+#             */
/*   Updated: 2022/03/28 06:33:45 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	so_long_draw_animate(t_so_long so)
{
	void *const	img[2] = {so->collectible, so->exit};
	int			x;
	int			y;

	so->player_face = 1;
	so->slime = 0;
	so->delete_lock = 0;
	so->running = 1;
	x = 0;
	while (x != so->map.size_x)
	{
		y = 0;
		so_long_put_image(so, so->walls.abyss, x * 32, 0);
		while (y != so->map.size_y)
		{
			so_long_clear_pos(so, x, y);
			if (so->map.data[y][x] & (4 + 8))
				so_long_put_pos(so, img[so->map.data[y][x] >> 3], x, y);
			++y;
		}
		++x;
	}
	so_long_put_pos(so, so->playerl, so->player.x, so->player.y);
}
