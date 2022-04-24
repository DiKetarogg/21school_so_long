/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:31:25 by jzoltan           #+#    #+#             */
/*   Updated: 2022/03/28 06:49:30 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "detail_so_long.h"

static int	(*get_action(int key))(t_so_long so_long)
{
	static struct s_action_key_pair const	actions[] = {
	{97, so_long_move_left},
	{100, so_long_move_right},
	{115, so_long_move_down},
	{119, so_long_move_up},
	{65307, so_long_close},
	{65362, so_long_move_up},
	{65361, so_long_move_left},
	{65364, so_long_move_down},
	{65363, so_long_move_right},
	{0, 0},
	};
	int										i;

	i = 0;
	while (actions[i].key != key && i != 9)
		++i;
	return (actions[i].action);
}

int	so_long_key_handler(int key, t_so_long so_long)
{
	int	(*action)(t_so_long);

	action = get_action(key);
	if (action)
	{
		action(so_long);
		so_long->request_flush = 1;
	}
	return (0);
}
