/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:31:20 by jzoltan           #+#    #+#             */
/*   Updated: 2022/03/28 04:15:34 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <ftio.h>
#include <so_long.h>

void	so_long_exit_win(t_so_long so_long)
{
	mlx_loop_end(so_long->mlx);
	ft_print(FT_STR, "\e[32mWon\n\e[0m", FT_FLUSH, 0);
}

void	so_long_exit_loss(t_so_long so_long)
{
	mlx_loop_end(so_long->mlx);
	ft_print(FT_STR, "\e[33mLost\n\e[0m", FT_FLUSH, 0);
}

int	so_long_move(t_so_long so_long, int x, int y)
{
	int const	c = so_long->map.data[y][x];

	if (c == 2)
		return (0);
	if (c == 9)
	{
		++so_long->move_counter;
		ft_print(FT_INT, so_long->move_counter, FT_STR, "\n", FT_FLUSH, 0);
		if (so_long->collectibles)
			return (1);
		so_long_exit_win(so_long);
		return (1);
	}
	if (c == 5)
	{
		--so_long->collectibles;
		so_long_clear_pos(so_long, x, y);
		so_long->map.data[y][x] = 0;
	}
	++so_long->move_counter;
	ft_print(FT_INT, so_long->move_counter, FT_STR, "\n", FT_FLUSH, 0);
	return (1);
}

void	so_long_restore_image(t_so_long so_long, int x, int y)
{
	if (so_long->map.data[y][x] == 9)
		so_long_put_image(so_long, so_long->exit, x * 32, (y + 1) * 32);
}

int	so_long_close(t_so_long so_long)
{
	mlx_loop_end(so_long->mlx);
	return (0);
}
