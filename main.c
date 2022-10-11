#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{	
	int	i;
	int	j;

	char	a = 'd';
	char	*b = &a ;
	char	*c = "VERAO";
	int	    d = 100;

	i = printf("original: %x, %c, %p, %s, %d\n", a, a, b, c, d);
	printf("count: %i\n", i);
	j = ft_printf("    mine: %x, %c, %p, %s, %d\n", a, a, b, c, d);
	printf("count: %i\n\n", j);

	int	e = 0;
	printf("original: ");
	i = printf("%x, %X ", e, e);
	printf(" - count: %i\n", i);

	ft_printf("mine: ");
	j = ft_printf("%x, %X ", e, e);
	printf(" - count: %i\n", j);

	return(0);
}