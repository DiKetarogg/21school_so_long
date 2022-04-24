/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 08:21:28 by jzoltan           #+#    #+#             */
/*   Updated: 2022/02/04 16:11:37 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		++i;
		++str;
	}
	return (i);
}

char	*ft_strjoin2(char const *str1, char const *str2)
{
	size_t const	size = ft_strlen(str1) + ft_strlen(str2) + 1;
	char			*str;
	char			*it;

	str = malloc(size * sizeof(char));
	if (!str)
		return (0);
	it = str;
	while (*str1)
	{
		*it = *str1;
		++it;
		++str1;
	}
	while (*str2)
	{
		*it = *str2;
		++it;
		++str2;
	}
	*it = 0;
	return (str);
}

char	*ft_strjoin3(char const *str1, char const *str2, char const *str3)
{
	size_t const	size = ft_strlen(str1) + ft_strlen(str2) + ft_strlen(str3)
		+ 1;
	char			*str;
	char			*it;

	str = malloc(size * sizeof(char));
	if (!str)
		return (0);
	it = str - 1;
	while (*str1)
		*++it = *str1++;
	while (*str2)
		*++it = *str2++;
	while (*str3)
		*++it = *str3++;
	*++it = 0;
	return (str);
}
