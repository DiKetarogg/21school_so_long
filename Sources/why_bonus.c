/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   why_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 05:51:56 by jzoltan           #+#    #+#             */
/*   Updated: 2022/03/28 06:31:31 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	why_slime_bonus(t_so_long so_long, t_slime *slime)
{
	slime->offset += slime->offset_sign;
	so_long_clear_pos(so_long, slime->new_x, slime->new_y);
	if (slime->offset * slime->offset_sign == 32)
	{
		so_long->map.data[slime->y][slime->x] = 65;
		so_long->map.data[slime->new_y][slime->new_x] = 33;
	}
	else if (slime->offset * slime->offset_sign == 64)
	{
		slime->moving = 0;
		so_long->map.data[slime->y][slime->x] = 1;
		slime->x = slime->new_x;
		slime->y = slime->new_y;
		return (so_long_put_pos(so_long, so_long->sleg
				[slime->ani][slime->frame], slime->x, slime->y));
	}
	if (slime->x != slime->new_x)
		so_long_put_pos_32(so_long, so_long->sleg[slime->ani][slime->frame],
			slime->x * 32 + slime->offset, slime->y * 32);
	else
		so_long_put_pos_32(so_long, so_long->sleg[slime->ani][slime->frame],
			slime->x * 32, slime->y * 32 + slime->offset);
}
