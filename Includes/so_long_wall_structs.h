/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_wall_structs.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:54:10 by jzoltan           #+#    #+#             */
/*   Updated: 2022/02/09 14:54:34 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_WALL_STRUCTS_H
# define SO_LONG_WALL_STRUCTS_H

typedef void							*t_mlx;
typedef void							*t_mlx_window;
typedef void							*t_mlx_image;

struct s_so_long_wall_back
{
	t_mlx_image	top_right;
	t_mlx_image	top;
	t_mlx_image	top_left;
	t_mlx_image	right;
	t_mlx_image	left;
	t_mlx_image	bottom_right;
	t_mlx_image	bottom_left;
};

struct s_so_long_wall_front_rl
{
	t_mlx_image	inner;
	t_mlx_image	outer;
};

typedef struct s_so_long_wall_front_rl	t_so_long_wall_front_rl;

struct s_so_long_wall_front_ul
{
	t_so_long_wall_front_rl	left;
	t_so_long_wall_front_rl	right;
	t_mlx_image				top[10];
};

typedef struct s_so_long_wall_front_ul	t_so_long_wall_front_ul;

struct s_so_long_wall_front
{
	t_so_long_wall_front_ul	lower;
	t_so_long_wall_front_ul	upper;
};

typedef struct s_so_long_wall_front		t_so_long_wall_front;
typedef struct s_so_long_wall_back		t_so_long_wall_back;

struct s_so_long_walls
{
	t_mlx_image				abyss;
	t_so_long_wall_back		back;
	t_so_long_wall_front	front;
	t_mlx_image				column;
};

typedef struct s_so_long_walls			t_so_long_walls;

struct s_so_long_tiles
{
	t_mlx_image	abyss;
	t_mlx_image	tileset[10];
};

#endif
