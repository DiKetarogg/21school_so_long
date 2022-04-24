/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_delete_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:17:30 by jzoltan           #+#    #+#             */
/*   Updated: 2022/03/28 07:05:16 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <stdlib.h>
#include <unistd.h>
#include <ft.h>
#include <mlx.h>

static void	terminate_thread(t_so_long so_long)
{
	so_long->running = 0;
	pthread_join(so_long->thread, 0);
}

void	so_long_delete(t_so_long so_long)
{
	int	i;

	terminate_thread(so_long);
	i = 0;
	while (i != sizeof(t_so_long_walls) / sizeof(void *) + 15)
	{
		if (((void **)&so_long->walls)[i])
			mlx_destroy_image(so_long->mlx, ((void **)&so_long->walls)[i]);
		++i;
	}
	i = -1;
	while (++i != 24)
	{
		if (so_long->sleg[0][i])
			mlx_destroy_image(so_long->mlx, so_long->sleg[0][i]);
	}
	if (so_long->slime_count)
		free(so_long->slime);
	mlx_destroy_window(so_long->mlx, so_long->window);
	mlx_destroy_display(so_long->mlx);
	free(so_long->mlx);
	free(so_long->img_map);
	free(so_long->map.data);
	free(so_long);
}
