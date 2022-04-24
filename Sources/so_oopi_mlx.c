/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_oopi_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:31:40 by jzoltan           #+#    #+#             */
/*   Updated: 2022/02/09 14:45:33 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>
#include <mlx_int.h>
#include <stdint.h>

void	so_long_put_filler(t_so_long so_long, void *img, int x, int y)
{
	XImage *const		it = ((t_img *)img)->image;
	XImage *const		src = ((t_img *)so_long->img_buff)->image;
	t_vector2i			i;
	t_vector2i const	size = {it->height, it->height};
	uint32_t			*temp;

	i.x = 0;
	while (i.x != size.x)
	{
		i.y = -1;
		while (++i.y != size.y)
		{
			temp = &((uint32_t *)(src->data + (i.y + y) * src->bytes_per_line))
			[i.x + x];
			if (!(*temp & 0xFF000000))
				continue ;
			*temp = ((uint32_t *)(it->data + i.y * it->bytes_per_line))[i.x];
		}
		++i.x;
	}
}

void	so_long_replace_image(t_so_long so_long, void *img, int x, int y)
{
	XImage *const		it = ((t_img *)img)->image;
	XImage *const		src = ((t_img *)so_long->img_buff)->image;
	t_vector2i			i;
	t_vector2i const	size = {it->height, it->height};

	i.x = 0;
	while (i.x != size.x)
	{
		i.y = -1;
		while (++i.y != size.y)
			((uint32_t *)(src->data + (i.y + y) * src->bytes_per_line))
			[i.x + x] = ((uint32_t *)(it->data + i.y
						* it->bytes_per_line))[i.x];
		++i.x;
	}
}

void	so_long_put_image(t_so_long so_long, void *img, int x, int y)
{
	XImage *const		s[2] = {
		((t_img *)so_long->img_buff)->image, ((t_img *)img)->image};
	float				a[3];
	t_vector4i			i;
	t_color				*c;
	t_color				*d;

	i = (t_vector4i){-1, -1, s[1]->width, s[1]->height};
	while (++i.x != i.z)
	{
		i.y = -1;
		while (++i.y != i.w)
		{
			c = (t_color *)(s[1]->data + i.y * s[1]->bytes_per_line + i.x * 4);
			d = (t_color *)(s[0]->data
					+ (i.y + y) * s[0]->bytes_per_line + (i.x + x) * 4);
			a[1] = (1.f - c->a / 255.f);
			a[2] = (1.f - d->a / 255.f);
			a[0] = ((1.f - a[1]) * a[2] + a[1]);
			d->r = ((1.f - a[1]) * a[2] * d->r + a[1] * c->r) / a[0];
			d->g = ((1.f - a[1]) * a[2] * d->g + a[1] * c->g) / a[0];
			d->b = ((1.f - a[1]) * a[2] * d->b + a[1] * c->b) / a[0];
			d->a = (1.f - a[0]) * 0xFF;
		}
	}
}

void	so_mlx_fix_transparent(void *img)
{
	uint32_t			*it;
	uint32_t const		*end = (uint32_t *)((t_img *)img)->image->data
		+ (((t_img *)img)->image->width * ((t_img *)img)->image->height);

	it = (uint32_t *)((t_img *)img)->image->data;
	while (it != end)
	{
		if (!(*it & 0xFFFFFF00))
			*it = 0;
		++it;
	}
}
