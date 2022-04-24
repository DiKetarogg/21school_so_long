/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detail_print.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzoltan <jzoltan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 07:03:56 by jzoltan           #+#    #+#             */
/*   Updated: 2022/02/09 10:30:45 by jzoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DETAIL_PRINT_H
# define DETAIL_PRINT_H

# include "detail_types.h"
# include <stdarg.h>
# include <stddef.h>

void	ft_print_int(va_list *args);
void	ft_print_str(va_list *args);

# ifdef FT_PRINT_FLUSH_ARG_H

void	ft_print_flush(va_list *args);

# else

void	ft_print_flush(void);

# endif

t_args	ft_print_get_args(void);

void	ft_print_save(char const *str);

#endif
