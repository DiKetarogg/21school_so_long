/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:51:10 by jzoltan           #+#    #+#             */
/*   Updated: 2022/02/04 12:53:02 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>
#include <stddef.h>

int	ft_atoi(char const *str)
{
	int	sign;
	int	num;

	while (ft_isspace(*str))
		++str;
	if (ft_isplusminus(*str))
	{
		sign = -(*str - '+' - 1);
		++str;
	}
	else
		sign = 1;
	while (*str == '0')
		++str;
	if (!ft_isdigit(*str))
		return (0);
	num = (*str - '0') * sign;
	++str;
	while (ft_isdigit(*str))
	{
		num *= 10;
		num += sign * (*str - '0');
		++str;
	}
	return (num);
}

void	ft_fill(void const *with, size_t value_size,
		void *ptr, size_t container_size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i != container_size)
	{
		j = 0;
		while (j != value_size)
		{
			((unsigned char *)ptr)[i + j] = ((unsigned char const *)with)[j];
			++j;
		}
		i += j;
	}
}
