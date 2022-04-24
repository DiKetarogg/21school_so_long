/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:53:21 by jzoltan           #+#    #+#             */
/*   Updated: 2022/02/09 14:56:38 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define FT_CNTRL 0x1
# define FT_PRINT 0x2
# define FT_SPACE 32
# define FT_BLANK 0x10
# define FT_GRAPH 0x4
# define FT_PUNCT 0x8
# define FT_ALPHA 0x40
# define FT_UPPER 0x80
# define FT_LOWER 0x100
# define FT_DIGIT 0x200
# define FT_XDIGIT 0x400
# define FT_NAME 0x800
# define FT_PLUSMINUS 0x1000

# include <stddef.h>
# include <stdint.h>

int			ft_atoi(char const *str);
int			ft_itoa(int value, char *buffer);
void		ft_fill(void const *with, size_t value_size,
				void *ptr, size_t container_size);
int			ft_strlen(char const *str);

void		*ft_memset(void *b, int c, size_t len);
void		**ft_array2(size_t arrayc, size_t rowc);

int			ft_is(int c, int flag);
int			ft_iscntrl(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
int			ft_isblank(int c);
int			ft_isgraph(int c);
int			ft_ispunct(int c);
int			ft_isalpha(int c);
int			ft_isupper(int c);
int			ft_islower(int c);
int			ft_isdigit(int c);
int			ft_isxdigit(int c);
int			ft_isplusminus(int c);
int			ft_isname(int c);

uint32_t	*ft_get_seed(void);
uint32_t	ft_rand(void);

#endif
