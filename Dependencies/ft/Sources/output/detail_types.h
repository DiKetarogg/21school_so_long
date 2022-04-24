/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detail_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 06:59:45 by jzoltan           #+#    #+#             */
/*   Updated: 2022/02/09 10:32:20 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DETAIL_TYPES_H
# define DETAIL_TYPES_H

# define FT_BUFFER_SIZE 40960

struct s_args
{
	char			buffer[FT_BUFFER_SIZE];
	char			inter[20];
	char *const		end;
	char			*it;
	int				lock;
	int				error;
};

typedef struct s_args	*t_args;
#endif
