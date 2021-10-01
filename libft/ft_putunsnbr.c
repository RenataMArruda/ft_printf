/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putunsnbr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rarruda <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/30 17:45:50 by rarruda       #+#    #+#                 */
/*   Updated: 2021/09/30 17:46:32 by rarruda       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	negative_nb(int nb)
{
	long	number;

	number = nb;
	if (nb < 0)
		number = 4294967296 + nb;
	return (number);
}

static int	count_digits(unsigned int number)
{
	int	count;

	count = 1;
	while (number > 9)
	{
		number /= 10;
		count++;
	}
	return (count);
}

int	ft_putunsnbr(int nb)
{
	int				count;
	int				i;
	unsigned int	copy;
	unsigned int	uns_nbr;

	uns_nbr = negative_nb(nb);
	copy = uns_nbr;
	count = count_digits(uns_nbr);
	i = 0;
	while (i < count)
	{
		uns_nbr = copy % ft_power(count - 1 - i);
		copy = copy / ft_power(count - 1 - i);
		ft_putchar(copy + 48);
		copy = uns_nbr;
		i++;
	}
	return (count);
}
