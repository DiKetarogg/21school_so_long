/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_parser_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:31:31 by jzoltan           #+#    #+#             */
/*   Updated: 2022/03/28 04:17:49 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <mlx.h>
#include <fcntl.h>
#include <so_long.h>
#include <ft.h>
#include <unistd.h>
#include <ftio.h>
#include <unistd.h>
#include <time.h>

static int	convert_map_c(int c)
{
	static int	code[256] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 5, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		17, 0, 0, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	return (code[c]);
}

static char	**allocate_map(t_ft_string string, size_t *x, size_t *y)
{
	t_ft_string_iterator	iterator;
	int						i;
	char					**array;

	i = ft_string_begin(string, &iterator);
	if (!i)
		return (0);
	while (i && (*iterator.it == '1'))
		i = ft_string_next_iterator(&iterator);
	if (*iterator.it != '\n')
		return (0);
	*x = ft_string_iterator_index(&iterator) + 2;
	if (*x == 2)
		return (0);
	*y = ft_string_size(string);
	if (*y % (*x - 1))
		return (0);
	*y = *y / (*x - 2) + 2;
	if (*y < 5)
		return (0);
	array = (char **)ft_array2(*y, *x);
	ft_memset(array[0], 2, *x * 2);
	ft_memset(array[*y - 2], 2, *x * 2);
	srand(time(0));
	return (array);
}

static int	parse_map_internal2(t_so_long so_long,
		t_ft_string_iterator *iterator,
		t_vector4i its, char **array)
{
	t_vector4i	icv;

	icv = (t_vector4i){1, 0, 0, 1};
	while (icv.x && ++its.y != its.w)
	{
		while (icv.x && ++its.x != its.z)
		{
			icv.x = ft_string_next_iterator(iterator);
			if (!convert_map_c(*iterator->it))
				return (ft_print(2, "Error\nInvalid character\n", 3, 0) * 0);
			array[its.y][its.x] = convert_map_c(*iterator->it);
			icv.z |= convert_map_c(*iterator->it);
			so_long->slime_count += convert_map_c(*iterator->it) == 33;
			so_long->collectibles += convert_map_c(*iterator->it) == 5;
			if (convert_map_c(*iterator->it) == 17 && !(rand() % icv.w))
				so_long->player = (t_vector2i){its.x, its.y + ++icv.w * 0};
		}
		if (!icv.x || *iterator->it != '1' || !ft_string_next_iterator(iterator)
			|| *iterator->it != '\n' || array[its.y][1] != 2)
			return (0 * ft_print(2, "Error\nInvalid map borders/dims\n", 3, 0));
		its.x = 0;
	}
	while (ft_string_next_iterator(iterator) && ++its.x != its.z)
		icv.y |= *iterator->it;
	return (((icv.z & 31) == 31 && icv.y == '1' && its.x == its.z) + 1);
}

static t_so_map	parse_map_internal(t_so_long so_long, t_ft_string string)
{
	t_ft_string_iterator	iterator;
	t_vector3uz				sizes;
	char					**array;

	array = allocate_map(string, &sizes.x, &sizes.y);
	if (!array && (1 | ft_print(2, "Error\nWrong border or size", 3, 0)))
		return ((t_so_map){0, 0, 0});
	if (!ft_string_make_iterator(string, &iterator, sizes.x - 2))
	{
		free(array);
		return ((t_so_map){0, 0, 0});
	}
	if (ft_string_last(string) == '\n' || ft_string_append_char(string, '\n'))
	{
		sizes.z = parse_map_internal2(so_long, &iterator,
				(t_vector4i){0, 1, sizes.x - 1, sizes.y - 2}, array);
		if (sizes.z == 1)
			ft_print(2, "Error\nNo E/C/P or wrong map end\n", 3, 0);
		else if (sizes.z == 2)
			return ((t_so_map){array, sizes.x, sizes.y});
		free(array);
		return ((t_so_map){0, 0, 0});
	}
	ft_print(FT_STR, "Error\nRead fail.\n", 3, 0);
	return ((t_so_map){0, 0, 0});
}

t_so_map	so_long_parse_map(t_so_long so_long, char const *name)
{
	t_ft_string	string;
	int			fd;
	t_so_map	map;

	so_long->collectibles = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		ft_print(2, "Error\nFailed to read file ", 2, name, 2, "\n", 3, 0);
		return ((t_so_map){0, 0, 0});
	}
	string = ft_string_new(4096);
	*ft_get_seed() += (size_t)string;
	if (!string)
		return ((t_so_map){0, 0, 0});
	if (!ft_string_append_fd(string, fd))
	{
		close(fd);
		ft_string_delete(string);
		return ((t_so_map){0, 0, 0});
	}
	close(fd);
	map = parse_map_internal(so_long, string);
	ft_string_delete(string);
	return (map);
}
