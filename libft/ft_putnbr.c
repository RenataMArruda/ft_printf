/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rarruda <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/25 17:57:48 by rarruda       #+#    #+#                 */
/*   Updated: 2020/09/28 17:24:27 by rarruda       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	negative_nb(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	if (nb < 0 && nb != -2147483648)
	{
		nb = nb * (-1);
		ft_putchar('-');
	}
	return (nb);
}

void	ft_putnbr(int nb)
{
	int	copy;
	int	count;
	int	i;

	count = 1;
	nb = negative_nb(nb);
	copy = nb;
	if (nb != -2147483648)
	{
		while (copy > 9)
		{
			copy /= 10;
			count++;
		}
		copy = nb;
		i = 0;
		while (i < count)
		{
			nb = copy % ft_power(count - 1 - i);
			copy = copy / ft_power(count - 1 - i);
			ft_putchar(copy + 48);
			copy = nb;
			i++;
		}
	}
}
