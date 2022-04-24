/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detail_so_long.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:51:11 by jzoltan           #+#    #+#             */
/*   Updated: 2022/02/09 14:51:12 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DETAIL_SO_LONG_H
# define DETAIL_SO_LONG_H

struct s_action_key_pair
{
	int	key;
	int	(*action)(t_so_long);
};

#endif
