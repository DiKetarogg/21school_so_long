/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:25:39 by jzoltan           #+#    #+#             */
/*   Updated: 2022/03/26 18:27:38 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	valid_arg(char const *str)
{
	int		dummy;

	(void)dummy;
	while (*str)
		++str;
	if (str[-1] != 'r' || str[-2] != 'e' || str[-3] != 'b' || str[-4] != '.')
	{
		dummy = write(STDERR_FILENO, "Map file wrong extension\n", 25);
		return (0);
	}
	return (1);
}
