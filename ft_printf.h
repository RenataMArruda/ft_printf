/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rarruda <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 10:50:03 by rarruda       #+#    #+#                 */
/*   Updated: 2021/10/08 10:51:25 by rarruda       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	return_cdiuxX(int i, char id);
int	return_s(char *str);
int	return_p(size_t *pointer);

#endif
