/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conversions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rarruda <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 11:41:36 by rarruda       #+#    #+#                 */
/*   Updated: 2021/10/08 10:47:11 by rarruda       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	return_cdiuxX(int i, char id)
{
	int	count;

	if (id == 'c')
	{
		ft_putchar(i);
		count = 1;
	}
	if (id == 'd' || id == 'i')
	{
		ft_putnbr(i);
		if (i >= 0)
			count = 1;
		else
			count = 2;
		while (i > 9 || i < -9)
		{
			i = i / 10;
			count++;
		}
	}
	if (id == 'u')
		count = ft_putunsnbr(i);
	if (id == 'x' || id == 'X')
		count = ft_puthex(i, id);
	return (count);
}

int	return_s(char *str)
{
	int	count;

	if (str == NULL)
		str = "(null)";
	ft_putstr(str);
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int	return_p(size_t *pointer)
{
	int					count;
	unsigned long long	addr;

	addr = (unsigned long long)pointer;
	count = ft_putpoi(addr);
	return (count);
}
