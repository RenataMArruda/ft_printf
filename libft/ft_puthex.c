/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rarruda <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/30 17:12:26 by rarruda       #+#    #+#                 */
/*   Updated: 2021/10/12 14:29:23 by rarruda       ########   odam.nl         */
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

int	ft_puthex(int nb, char id)
{
	int				remainder[9];
	int				i;
	unsigned int	uns_nb;

	uns_nb = negative_nb(nb);
	i = 0;
	while (uns_nb > 0)
	{
		remainder[i] = uns_nb % 16;
		uns_nb = uns_nb / 16;
		if (uns_nb > 0)
			i++;
	}
	uns_nb = i + 1;
	while (i >= 0)
	{
		if (remainder[i] >= 0 && remainder[i] <= 9)
			ft_putchar(remainder[i] + 48);
		else if (remainder[i] >= 10 && id == 'x')
			ft_putchar(remainder[i] + 87);
		else if (remainder[i] >= 10 && id == 'X')
			ft_putchar(remainder[i] + 55);
		i--;
	}
	return (uns_nb);
}
