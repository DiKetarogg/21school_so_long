/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:53:23 by jzoltan           #+#    #+#             */
/*   Updated: 2022/02/09 14:53:24 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_TYPES_H
# define SO_LONG_TYPES_H

struct s_vector2i
{
	int	x;
	int	y;
};

struct s_vector3i
{
	int	x;
	int	y;
	int	z;
};

struct s_vector4i
{
	int	x;
	int	y;
	int	z;
	int	w;
};

struct s_vector5i
{
	int	x;
	int	y;
	int	z;
	int	w;
	int	v;
};

typedef struct s_vector2i	t_vector2i;
typedef struct s_vector3i	t_vector3i;
typedef struct s_vector4i	t_vector4i;
typedef struct s_vector5i	t_vector5i;

struct s_vector2uz
{
	size_t	x;
	size_t	y;
};

struct s_vector3uz
{
	size_t	x;
	size_t	y;
	size_t	z;
};

struct s_vector4uz
{
	size_t	x;
	size_t	y;
	size_t	z;
	size_t	w;
};

typedef struct s_vector2uz	t_vector2uz;
typedef struct s_vector3uz	t_vector3uz;
typedef struct s_vector4uz	t_vector4uz;

struct s_color
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
};

typedef struct s_color		t_color;

#endif
