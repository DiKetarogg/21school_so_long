/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:05:23 by jzoltan           #+#    #+#             */
/*   Updated: 2022/02/06 05:45:33 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_itoa(int n, char *buffer)
{
	int			digits;
	int			temp;
	int const	sign = (n < 0) * -2 + 1;

	digits = 0;
	temp = n;
	while (temp)
	{
		temp /= 10;
		++digits;
	}
	digits += sign < 0;
	buffer += digits;
	*buffer = 0;
	*--buffer = n % 10 * sign + '0';
	n /= 10 * sign;
	while (n)
	{
		--buffer;
		*buffer = n % 10 + '0';
		n /= 10;
	}
	if (sign < 0)
		*--buffer = '-';
	return (digits);
}
