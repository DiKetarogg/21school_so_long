/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:31:33 by jzoltan           #+#    #+#             */
/*   Updated: 2022/03/28 06:42:13 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <mlx.h>
#include <ft.h>
#include <unistd.h>
#include <ftio.h>

#define WLS "Res/Dungeon Tileset/walls/"
#define WLS_LT "Res/Dungeon Tileset/walls/front/lower/top/"
#define WLS_UT "Res/Dungeon Tileset/walls/front/upper/top/"
#define TI_ES "Res/Dungeon Tileset/tiles/"
#define CO_ES "Res/32x32 In-Game Items Asset Pack/"
#define PL_ES "Res/The Cutest Hero/"
#define SLML "Res/Slime/"

static int	so_long_init(t_so_long so_long, const char *map_path,
		int x, int y)
{
	*ft_get_seed() += (size_t)so_long;
	so_long->screen_x = x;
	so_long->screen_y = y;
	so_long->mlx = mlx_init();
	if (!so_long->mlx)
		return (0);
	so_long->map = so_long_parse_map(so_long, map_path);
	if (!so_long->map.data)
	{
		free(so_long->mlx);
		return (0);
	}
	so_long->window = mlx_new_window(so_long->mlx, x,
			y, "so_long");
	if (!so_long->window)
	{
		free(so_long->mlx);
		free(so_long->map.data);
		return (0);
	}
	so_long->img_buff = mlx_new_image(so_long->mlx, so_long->map.size_x * 32,
			(so_long->map.size_y + 1) * 32);
	mlx_key_hook(so_long->window, so_long_key_handler, so_long);
	mlx_hook(so_long->window, 17, 1, so_long_close, so_long);
	return (1);
}

static int	so_long_images(void **ptr, void *mlx, char *const *paths, int size)
{
	int	dummy;
	int	error;
	int	i;

	i = 0;
	error = 1;
	while (i != size)
	{
		ptr[i] = mlx_xpm_file_to_image(mlx, paths[i], &dummy, &dummy);
		if (!ptr[i])
		{
			dummy = write(STDERR_FILENO, "Failed to read file ", 20)
				+ write(STDERR_FILENO, paths[i], ft_strlen(paths[i]))
				+ write(STDERR_FILENO, "\n", 1);
			error = 0;
		}
		++i;
	}
	return (error);
}

static int	so_long_init3(t_so_long so_long)
{
	char *const	path[2][10] = {{TI_ES "grey/01.xpm",
		TI_ES "grey/02.xpm", TI_ES "grey/03.xpm",
		TI_ES "grey/04.xpm", TI_ES "grey/05.xpm", TI_ES "grey/06.xpm",
		TI_ES "grey/07.xpm", TI_ES "grey/08.xpm",
		TI_ES "grey/09.xpm", TI_ES "grey/10.xpm"}, {
		TI_ES "brown/01.xpm", TI_ES "brown/02.xpm", TI_ES "brown/03.xpm",
		TI_ES "brown/04.xpm", TI_ES "brown/05.xpm", TI_ES "brown/06.xpm",
		TI_ES "brown/07.xpm", TI_ES "brown/08.xpm",
		TI_ES "brown/09.xpm", TI_ES "brown/10.xpm"}};
	char *const	co[11] = {
		CO_ES "StaticApple.xpm", CO_ES "StaticBigHealthPotion.xpm",
		CO_ES "StaticBigManaPotion.xpm", CO_ES "StaticBlueCrystal.xpm",
		CO_ES "StaticChickenThigh.xpm", CO_ES "StaticCoin.xpm",
		CO_ES "StaticGreenCrystal.xpm", CO_ES "StaticHeart.xpm",
		CO_ES "StaticScroll.xpm", CO_ES "StaticSmallHealthPotion.xpm",
		CO_ES "StaticSmallManaPotion.xpm"};
	char *const	pl[2] = {PL_ES "idle/left/0.xpm", PL_ES "idle/right/0.xpm"};

	so_long->error &= so_long_images((void **)&so_long->tiles, so_long->mlx,
			path[ft_rand() % 2], 10);
	so_long->error &= so_long_images(&so_long->collectible, so_long->mlx,
			&co[ft_rand() % 10], 1);
	so_long->error &= so_long_images(&so_long->playerl, so_long->mlx, pl, 2);
	so_long->request_flush = 0;
	return (so_long->error);
}

static int	so_long_init2(t_so_long so_long)
{
	char *const	paths[38] = {WLS "abyss.xpm",
		WLS "back/top_right.xpm", WLS "back/top.xpm",
		WLS "back/top_left.xpm", WLS "back/right.xpm",
		WLS "back/left.xpm", WLS "back/bottom_right.xpm",
		WLS "back/bottom_left.xpm", WLS "front/lower/left/inner.xpm",
		WLS "front/lower/left/outer.xpm", WLS "front/lower/right/inner.xpm",
		WLS "front/lower/right/outer.xpm", WLS_LT "01.xpm", WLS_LT "02.xpm",
		WLS_LT "03.xpm", WLS_LT "04.xpm", WLS_LT "05.xpm", WLS_LT "06.xpm",
		WLS_LT "07.xpm", WLS_LT "08.xpm", WLS_LT "09.xpm", WLS_LT "10.xpm",
		WLS "front/upper/left/inner.xpm", WLS "front/upper/left/outer.xpm",
		WLS "front/upper/right/inner.xpm", WLS "front/upper/right/outer.xpm",
		WLS_UT "01.xpm", WLS_UT "02.xpm", WLS_UT "03.xpm", WLS_UT "04.xpm",
		WLS_UT "05.xpm", WLS_UT "06.xpm", WLS_UT "07.xpm", WLS_UT "08.xpm",
		WLS_UT "09.xpm", WLS_UT "10.xpm", WLS "column.xpm", WLS "exit.xpm"};
	char *const	slime[] = {SLML "01.xpm", SLML "02.xpm", SLML "03.xpm", SLML
		"04.xpm", SLML "05.xpm", SLML "06.xpm", SLML "11.xpm", SLML "12.xpm",
		SLML "13.xpm", SLML "14.xpm", SLML "15.xpm", SLML "16.xpm",
		SLML "21.xpm", SLML "22.xpm", SLML "23.xpm", SLML "24.xpm",
		SLML "25.xpm", SLML "26.xpm", SLML "31.xpm", SLML "32.xpm",
		SLML "33.xpm", SLML "34.xpm", SLML "35.xpm", SLML "36.xpm"};

	so_long->error = so_long_images((void **)&so_long->walls,
			so_long->mlx, paths, 38);
	return (so_long->error = so_long_images((void **)so_long->sleg,
			so_long->mlx, slime, 24), so_long_init3(so_long));
}

t_so_long	so_long_new(char const *map_file, int screen_x, int screen_y)
{
	t_so_long	so_long;

	so_long = malloc(sizeof(struct s_so_long));
	so_long->slime_count = 0;
	if (!so_long || !so_long_init(so_long, map_file, screen_x, screen_y))
	{
		free(so_long);
		return (0);
	}
	so_long->move_counter = 0;
	if (!so_long->img_buff)
	{
		free(so_long->mlx);
		free(so_long->map.data);
		return (0);
	}
	so_long->img_map = 0;
	if (!so_long_init2(so_long) || !so_long_set_img_map(so_long))
	{
		so_long_delete(so_long);
		return (0);
	}
	so_long_flush_screen(so_long);
	ft_print(FT_STR, "\e[36m", 0);
	return (so_long);
}
