/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putpoi.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rarruda <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 15:18:24 by rarruda       #+#    #+#                 */
/*   Updated: 2021/09/30 17:42:47 by rarruda       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putpoi(unsigned long long addr)
{
	int		remainder[16];
	int		i;

	i = 0;
	while (addr > 0)
	{
		remainder[i] = addr % 16;
		addr = addr / 16;
		if (addr > 0)
			i++;
	}
	addr = i + 1;
	write(1, "0x", 2);
	while (i >= 0)
	{
		if (remainder[i] >= 0 && remainder[i] <= 9)
			ft_putchar(remainder[i] + 48);
		else
			ft_putchar(remainder[i] + 87);
		i--;
	}
	return (addr + 2);
}
