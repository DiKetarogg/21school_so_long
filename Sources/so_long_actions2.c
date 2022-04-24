/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_actions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:30:33 by jzoltan           #+#    #+#             */
/*   Updated: 2022/03/28 06:37:12 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <ftio.h>

int	so_long_move_up(t_so_long so_long)
{
	if (so_long_move(so_long, so_long->player.x, so_long->player.y - 1))
	{
		so_long_clear_pos(so_long, so_long->player.x, so_long->player.y);
		so_long_restore_image(so_long, so_long->player.x, so_long->player.y);
		--so_long->player.y;
		if (so_long->player_face)
		{
			so_long_put_image(so_long, so_long->playerl,
				so_long->player.x * 32,
				(so_long->player.y + 1) * 32);
		}
		else
		{
			so_long_put_image(so_long, so_long->playerr,
				so_long->player.x * 32,
				(so_long->player.y + 1) * 32);
		}
	}
	return (0);
}

int	so_long_move_left(t_so_long so_long)
{
	if (so_long_move(so_long, so_long->player.x - 1, so_long->player.y))
	{
		so_long_clear_pos(so_long, so_long->player.x, so_long->player.y);
		so_long_restore_image(so_long, so_long->player.x, so_long->player.y);
		--so_long->player.x;
		so_long_put_image(so_long, so_long->playerl,
			so_long->player.x * 32,
			(so_long->player.y + 1) * 32);
		so_long->player_face = 1;
	}
	return (0);
}

int	so_long_move_down(t_so_long so_long)
{
	if (so_long_move(so_long, so_long->player.x, so_long->player.y + 1))
	{
		so_long_clear_pos(so_long, so_long->player.x, so_long->player.y);
		so_long_restore_image(so_long, so_long->player.x, so_long->player.y);
		++so_long->player.y;
		if (so_long->player_face)
		{
			so_long_put_image(so_long, so_long->playerl,
				so_long->player.x * 32,
				(so_long->player.y + 1) * 32);
		}
		else
		{
			so_long_put_image(so_long, so_long->playerr,
				so_long->player.x * 32,
				(so_long->player.y + 1) * 32);
		}
	}
	return (0);
}

int	so_long_move_right(t_so_long so_long)
{
	if (so_long_move(so_long, so_long->player.x + 1, so_long->player.y))
	{
		so_long_clear_pos(so_long, so_long->player.x, so_long->player.y);
		so_long_restore_image(so_long, so_long->player.x, so_long->player.y);
		++so_long->player.x;
		so_long_put_image(so_long, so_long->playerr,
			so_long->player.x * 32,
			(so_long->player.y + 1) * 32);
		so_long->player_face = 0;
	}
	return (0);
}
