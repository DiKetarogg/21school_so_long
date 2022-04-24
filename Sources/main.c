/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:45:43 by jzoltan           #+#    #+#             */
/*   Updated: 2022/03/28 06:36:01 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <mlx.h>

static int	render(t_so_long so_long)
{
	if (so_long->request_flush)
	{
		so_long_flush_screen(so_long);
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
