/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:45:43 by jzoltan           #+#    #+#             */
/*   Updated: 2022/03/28 05:44:30 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <mlx.h>
#include <ft.h>

static void	not_so_render(t_so_long so_long)
{
	if (so_long->map.data[so_long->player.y][so_long->player.x] == 33)
		so_long_exit_loss(so_long);
	if (so_long->map.data[so_long->player.y][so_long->player.x] == 65)
	{
		if (so_long->player_face)
		{
			so_long_put_image(so_long, so_long->playerl,
				so_long->player.x * 32,
				(so_long->player.y + 1) * 32);
		}
		else
		{
			so_long_put_image(so_long, so_long->playerl,
				so_long->player.x * 32,
				(so_long->player.y + 1) * 32);
		}
	}
}

static int	render(t_so_long so_long)
{
	static char	buffer[20];

	not_so_render(so_long);
	if (so_long->request_flush)
	{
		so_long_flush_screen(so_long);
		mlx_string_put(so_long->mlx, so_long->window, so_long->screen_x / 2,
			20, 0x0, buffer);
		ft_itoa(so_long->move_counter, buffer);
		mlx_string_put(so_long->mlx, so_long->window, so_long->screen_x / 2,
			20, 0x4FE71ACC, buffer);
		so_long->request_flush = 0;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_so_long	game;
	int			dummy;

	(void)dummy;
	if (argc != 2)
	{
		dummy = write(STDERR_FILENO, "Map file not provided.\n", 23);
		return (1);
	}
	if (argc > 2)
	{
		errno = E2BIG;
		perror(0);
		return (1);
	}
	if (!valid_arg(argv[1]))
		return (1);
	so_long_key_handler(0, 0);
	game = so_long_new(argv[1], 720, 480);
	if (!game)
		return (1);
	mlx_loop_hook(game->mlx, render, game);
	so_long_loop(game);
	so_long_delete(game);
}
