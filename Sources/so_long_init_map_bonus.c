/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init_map_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 00:02:11 by jzoltan           #+#    #+#             */
/*   Updated: 2022/03/28 06:30:34 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

static void	move_slime(t_so_long so_long, t_slime *slime)
{
	int	direction;
	int	tries;

	direction = 4;
	tries = 0;
	if (so_long->map.data[slime->y - 1][slime->x] == 1)
		direction = ++tries;
	if (so_long->map.data[slime->y][slime->x + 1] == 1 && !(rand() % ++tries))
		direction = 5;
	if (so_long->map.data[slime->y][slime->x - 1] == 1 && !(rand() % ++tries))
		direction = 6;
	if (so_long->map.data[slime->y + 1][slime->x] == 1 && !(rand() % ++tries))
		direction = 7;
	slime->new_y = slime->y + ((direction > 6) - (direction < 3));
	slime->new_x = slime->x + ((direction % 3) - 1);
	slime->moving = (slime->new_y != slime->y || slime->new_x != slime->x);
	slime->offset = 0;
	slime->offset_sign = (slime->new_x - slime->x
			+ (slime->new_y - slime->y)) * 2;
	so_long->map.data[slime->new_y][slime->new_x] = 65;
}

static void	so_slime(t_so_long so_long, t_slime *slime)
{
	if (slime->frame > 5)
		slime->frame = 0;
	if (!slime->moving && !(rand() % 10))
		move_slime(so_long, slime);
	so_long_clear_pos(so_long, slime->x, slime->y);
	if (slime->moving)
		why_slime_bonus(so_long, slime);
	else
		so_long_put_pos(so_long, so_long->sleg[slime->ani][slime->frame],
			slime->x, slime->y);
}

static void	*so_animation_cycle(void *so_long)
{
	struct s_so_long *const	so = so_long;
	int						i;
	clock_t					end;

	so->delete_lock = 1;
	end = 0;
	while (so->running)
	{
		so->request_flush = 1;
		if (clock() < end)
			usleep((end - clock()) * (1000000 / CLOCKS_PER_SEC));
		end = clock() + CLOCKS_PER_SEC / 25;
		i = -1;
		while (++i != so->slime_count && so->running)
		{
			if (++so->slime[i].slow >= 10 && rand() % 10)
			{
				++so->slime[i].frame;
				so->slime[i].slow = 0;
			}
			so_slime(so, &so->slime[i]);
		}
	}
	so->delete_lock = 0;
	return (0);
}

static void	so_animate_some_slime(t_so_long so_long)
{
	int	i;

	i = -1;
	while (++i != so_long->slime_count)
		so_long->slime[i].ani = rand() % 4;
	so_long->delete_lock = 0;
	so_long->running = 1;
	pthread_create(&so_long->thread, 0, &so_animation_cycle, so_long);
	so_long->player_face = 1;
	so_long_put_pos(so_long, so_long->playerl, so_long->player.x,
		so_long->player.y);
}

void	so_long_draw_animate(t_so_long s)
{
	void *const	img[2] = {s->collectible, s->exit};
	t_vector3i	l;

	if (s->slime_count)
		s->slime = malloc(s->slime_count * sizeof(t_slime));
	if (s->slime_count && !s->slime)
		return (so_long_delete(s), (void)exit(2));
	l = (t_vector3i){-1, 0, 0};
	while (++l.x != s->map.size_x)
	{
		l.y = -1;
		so_long_put_image(s, s->walls.abyss, l.x * 32, 0);
		while (++l.y != s->map.size_y)
		{
			so_long_clear_pos(s, l.x, l.y);
			if (s->map.data[l.y][l.x] & (4 + 8))
				so_long_put_pos(s, img[s->map.data[l.y][l.x] >> 3], l.x, l.y);
			else if (s->map.data[l.y][l.x] & 32)
				s->slime[l.z] = (t_slime){l.x, l.y, l.x, l.y, 0, 0, 0, 0, 0, 0};
			if (s->map.data[l.y][l.x] & 32)
				so_long_put_pos(s, s->sleg[s->slime[l.z++].ani][0], l.x, l.y);
		}
	}
	so_animate_some_slime(s);
}
