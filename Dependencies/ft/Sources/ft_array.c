/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:33:32 by jzoltan           #+#    #+#             */
/*   Updated: 2022/02/07 10:07:05 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

void	**ft_array2(size_t arrayc, size_t rowc)
{
	size_t	size;
	void	*ptr;
	uint8_t	*from;
	uint8_t	**it;
	size_t	i;

	size = rowc * arrayc;
	if (!size || (size / arrayc != rowc))
		return (0);
	size += (arrayc + 1) * sizeof(void *);
	ptr = malloc(size);
	if (!ptr)
		return (0);
	it = ptr;
	from = (uint8_t *)((uint8_t **)(ptr) + arrayc + 1);
	i = 0;
	while (i != arrayc)
	{
		*it = from;
		++it;
		from += rowc;
		++i;
	}
	*it = 0;
	return (ptr);
}
