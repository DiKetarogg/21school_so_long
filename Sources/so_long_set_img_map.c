/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_set_img_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:31:36 by jzoltan           #+#    #+#             */
/*   Updated: 2022/03/28 00:22:29 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <ft.h>

static uint16_t	surroundings(char *const *mp, int x)
{
	return (((mp[-1][x - 1] & 3) << 14)
		+ ((mp[-1][x] & 3) << 12)
		+ ((mp[-1][x + 1] & 3) << 10)
		+ ((mp[0][x - 1] & 3) << 8)
		+ ((mp[0][x + 1] & 3) << 6)
		+ ((mp[1][x - 1] & 3) << 4)
		+ ((mp[1][x] & 3) << 2)
		+ ((mp[1][x + 1] & 3))
		);
}

static void	img_set_code(t_so_long so_long, uint16_t code, size_t x, size_t y)
{
	uint32_t	index;

	if (code < 8)
		so_long->img_map[y][x] = ((void **)&so_long->walls)[code];
	else if (code < 12)
	{
		so_long->img_map[y][x] = ((void **)&so_long->walls.front.lower.left)
		[code - 8];
		so_long->img_map[y - 1][x] = ((void **)&so_long->walls.front.upper.left)
		[code - 8];
	}
	else if (code < 14)
	{
		index = ft_rand() % 10;
		so_long->img_map[y][x] = so_long->walls.front.lower.top[index];
		so_long->img_map[y - 1][x] = so_long->walls.front.upper.top[index];
	}
	else if (code == 14)
		so_long->img_map[y][x] = so_long->walls.back.top;
	else if (code < 17)
		so_long->img_map[y][x] = ((void **)&so_long->walls.back.right)
		[code - 15];
	else
		so_long->img_map[y][x] = so_long->walls.column;
}

//	static uint16_t const	masks[14] = {21845, 8596, 8533, 8773, 5701, 20884,
//		38229, 22869, 21846, 21861, 5704, 20872, 21832, 0};

static void	img_init(t_so_long so_long, t_vector4i ic)
{
	static uint16_t	masks[18] = {21845, 8596, 8533, 8773, 5701, 20884, 38229,
		22869, 21846, 5704, 21861, 20872, 21832, 21862, 39253, 38245, 22870, 0};

	while (++ic.y != so_long->map.size_y - 1)
	{
		ic.x = 0;
		while (++ic.x != so_long->map.size_x - 1)
		{
			ic.z = -1;
			if (so_long->map.data[ic.y][ic.x] != 2)
			{
				so_long->img_map[ic.y][ic.x] = so_long->tiles[ft_rand() % 10];
				continue ;
			}
			ic.w = surroundings(&so_long->map.data[ic.y], ic.x);
			while (++ic.z != 18)
			{
				if (masks[ic.z] & ic.w)
					continue ;
				img_set_code(so_long, ic.z, ic.x, ic.y);
				break ;
			}
		}
	}
	so_long_draw_animate(so_long);
}

int	so_long_set_img_map(t_so_long so_long)
{
	void		***img_map;
	t_vector2i	it;

	so_long->img_map = (void ***)ft_array2(so_long->map.size_y,
			(so_long->map.size_x) * sizeof(void ************));
	if (!so_long->img_map)
		return (0);
	img_map = so_long->img_map;
	it = (t_vector2i){0, 0};
	while (it.x != so_long->map.size_x)
	{
		img_map[0][it.x] = so_long->walls.abyss;
		img_map[so_long->map.size_y - 1][it.x] = so_long->walls.abyss;
		++it.x;
	}
	while (it.y != so_long->map.size_y)
	{
		so_long->map.data[it.y][0] = 2;
		so_long->map.data[it.y][so_long->map.size_x - 1] = 2;
		img_map[it.y][0] = so_long->walls.abyss;
		img_map[it.y][so_long->map.size_x - 1] = so_long->walls.abyss;
		++it.y;
	}
	img_init(so_long, (t_vector4i){0, 0, 0, 0});
	return (1);
}
