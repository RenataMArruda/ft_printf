#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{	
	char	a = 'd';
	int		b = 42;
	char	c = 'Z';

	int	i;
	i = printf("original: %2c,%-2c,%3c\n", a, b, c);
	printf("count: %i\n", i);
	int	j;
	j = ft_printf("     meu: %2c,%-2c,%3c\n", a, b, c);
	printf("     count: %i\n\n", j);

	return(0);
}
