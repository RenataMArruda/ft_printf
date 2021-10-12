/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rarruda <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 15:14:17 by rarruda       #+#    #+#                 */
/*   Updated: 2021/10/08 10:54:46 by rarruda       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_char(const char *str, int i)
{
	ft_putchar(str[i]);
	return (1);
}

static int	print_argum(const char *str, int i, va_list args, int return_value)
{
	if (str[i] == '%')
	{
		ft_putchar(str[i]);
		return_value++;
	}
	else if (str[i] == 'c' || str[i] == 'd' || str[i] == 'i' || \
			str[i] == 'u' || str[i] == 'x' || str[i] == 'X')
		return_value += return_cdiuxX(va_arg(args, int), str[i]);
	else if (str[i] == 's')
		return_value += return_s(va_arg(args, char *));
	else if (str[i] == 'p')
		return_value += return_p(va_arg(args, void *));
	else
		return (-1);
	return (return_value);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		value;
	int		return_value;
	va_list	args;

	va_start(args, str);
	return_value = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			return_value += print_char(str, i);
		else
		{
			i++;
			value = print_argum(str, i, args, return_value);
			if (value == -1)
				i--;
			else
				return_value = value;
		}
		i++;
	}
	va_end(args);
	return (return_value);
}
