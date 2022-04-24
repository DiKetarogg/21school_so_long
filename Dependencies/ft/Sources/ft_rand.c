/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:38:05 by jzoltan           #+#    #+#             */
/*   Updated: 2022/02/06 05:30:47 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdint.h>

uint32_t	*ft_get_seed(void)
{
	static uint32_t	seed = (uint32_t)0xa4c92fda;

	return (&seed);
}

uint32_t	ft_rand(void)
{
	static uint32_t	*x = 0;

	if (!x)
		x = ft_get_seed();
	*x ^= *x << 13;
	*x ^= *x >> 17;
	*x ^= *x << 5;
	return (*x);
}
