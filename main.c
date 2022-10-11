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
	
	return(0);
}