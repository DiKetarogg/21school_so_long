/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:51:14 by jzoltan           #+#    #+#             */
/*   Updated: 2022/03/28 06:49:54 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "so_long_wall_structs.h"
# include <stddef.h>
# include <stdint.h>
# include <so_long_types.h>
# include <pthread.h>

struct s_so_long_map
{
	char	**data;
	int		size_x;
	int		size_y;
};

typedef struct s_so_long_slime
{
	int			x;
	int			y;
	int			new_x;
	int			new_y;
	int			moving;
	int			ani;
	int			frame;
	int			slow;
	int			offset;
	int			offset_sign;
}	t_slime;

typedef struct s_so_long_map	t_so_map;

struct s_so_long
{
	t_mlx			mlx;
	t_mlx_window	window;
	int				screen_x;
	int				screen_y;
	t_so_map		map;
	void			***img_map;
	t_so_long_walls	walls;
	t_mlx_image		exit;
	t_mlx_image		collectible;
	t_mlx_image		tiles[10];
	t_mlx_image		playerl;
	t_mlx_image		playerr;
	t_mlx_image		img_buff;
	uint64_t		collectibles;
	t_vector2i		player;
	int				move_counter;
	int				player_face;
	int				error;
	int				slime_count;
	int				running;
	int				delete_lock;
	int				request_flush;
	pthread_t		thread;
	t_mlx_image		sleg[4][6];
	t_slime			*slime;	
};

typedef struct s_so_long		*t_so_long;

t_so_long					so_long_new(char const *str, int screen_x,
								int screen_y);

int							so_long_key_handler(int key, t_so_long so_long);

int							so_long_loop(t_so_long so_long);

int							so_long_move_up(t_so_long so_long);
int							so_long_move_left(t_so_long so_long);
int							so_long_move_down(t_so_long so_long);
int							so_long_move_right(t_so_long so_long);

int							so_long_close(t_so_long so_long);

t_so_map					so_long_parse_map(t_so_long so_long,
								char const *name);

uint16_t					so_rand(void);
uint16_t					*so_get_seed(void);

void						so_long_delete(t_so_long so_long);

int							so_long_set_img_map(t_so_long so_long);

void						so_long_clear_pos(t_so_long so_long, int x, int y);
int							so_long_flush_screen(t_so_long so_long);
void						so_long_draw_animate(t_so_long so);
void						so_long_put_pos_32(t_so_long so_long, void *img,
								int x, int y);

void						so_long_put_image(t_so_long so_long,
								void *img, int x, int y);
void						so_long_put_filler(t_so_long so_long,
								void *img, int x, int y);
void						so_long_replace_image(t_so_long so_long,
								void *img, int x, int y);

void						so_long_restore_image(t_so_long so_long,
								int x, int y);
int							so_long_move(t_so_long so_long, int x, int y);
void						so_long_exit_win(t_so_long so_long);
void						so_long_exit_loss(t_so_long so_long);

int							valid_arg(char const *str);
void						so_long_put_pos(t_so_long so_long, void *img, int x,
								int y);

void						why_slime_bonus(t_so_long so_long, t_slime *slime);
#endif
