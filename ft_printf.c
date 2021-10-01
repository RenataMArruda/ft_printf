/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rarruda <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/15 15:14:17 by rarruda       #+#    #+#                 */
/*   Updated: 2021/10/01 18:57:28 by rarruda       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//apagar aqui:
#include <stdio.h>

static int	return_di(int i)
{
	int	count;

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
	return (count);
}

static int	count_conversions(const char *str)
{
	int	i;
	int	conversion;

	i = 0;
	conversion = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] == '%')
			i++;
		else if (str[i] == '%')
			conversion++;
		i++;
	}
	return (conversion);
}	

static int	return_uxX(int i, char id)
{
	int	count;

	if (id == 'u')
		count = ft_putunsnbr(i);
	if (id == 'x' || id == 'X')
		count = ft_puthex(i, id);
	return (count);
}

static int	return_s(char *str)
{
	int	count;

	ft_putstr(str);
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

static int	return_p(size_t *pointer)
{
	int					count;
	unsigned long long	addr;

	addr = (unsigned long long)pointer;
	count = ft_putpoi(addr);
	return (count);
}

static void	check_number(const char *str, int i)
{
	int		negative;
	int		start;
	int		number;
	char	*digits;

	negative = 1;
	start = 0;
	number = 0;
	i++;
	while (str[i] == '-' || (str[i] >= '0' && str[i] <= '9')) //até identificar a letra
	{
		if (str[i] == '-')
		{
			negative = -1;
			while (str[i] == '-')
				i++;
		}
//		depois do traço(s) vejo o que vem:
//			c direto (ver o caso para outras letras depois)
//				ignora traços e escreve a letra
//			número
//				seguido de letra 
//					ve direitinho
//				sem letra depois
//					erro
		if (str[i] >= '0' && str[i] <= '9')
		{
			start = i;
			while (str[i] >= '0' && str[i] <= '9')
			   i++;
			digits = malloc((i - start + 1) * sizeof(char));
//			if (digits == NULL)
//				return (NULL)
			while (start < i)
			{
				digits[number] = str[start];
				start++;
				number++;
			}
			digits[number] = '\0';
			number = atoi(digits);
printf("%d/n", number);
			//salvar sequencia de numeros (de start a i) em uma string 
			//usar atoi para obter um numero
			//dependendo a letra que vem depois tem que checar os limites aceitaveis do numero
			//free digits depois
		}
		i++;  	
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		return_value;
	int		conversion;
	va_list	args;

	va_start(args, str);

	conversion = count_conversions(str);
//printf("     %%: %d\n", conversion);	

	return_value = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			return_value++;
		}
		else
		{	
			if (str[i + 1] == '%')
			{
				ft_putchar(str[i + 1]);
				return_value++;
				i++;
			}
			else if (str[i + 1] == '-' || (str[i + 1] >= '0' && str[i + 1] <= '9'))
			{
//fazer check_number retornar numero de digitos depois!!
				check_number(str, i);
			}
			else
			{
				if (str[i + 1] == 'i' || str[i + 1] == 'd')
					return_value += return_di(va_arg(args, int));
				if (str[i + 1] == 'u' || str[i + 1] == 'x' || str[i + 1] == 'X')
					return_value += return_uxX(va_arg(args, int), str[i + 1]);
				if (str[i + 1] == 'c')
				{
					ft_putchar(va_arg(args, int));
					return_value++;
				}
				if (str[i + 1] == 's')
					return_value += return_s(va_arg(args, char *));
				if (str[i + 1] == 'p')
					return_value += return_p(va_arg(args, void *));
				i++;
			}
		}
		i++;
	}
	va_end(args);
	return (return_value);
}
