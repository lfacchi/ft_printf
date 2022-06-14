#include "ft_printf.h"
#include <stdio.h>




int main()
{
	unsigned int tst = 4294967295;
	printf("%u", tst);
	int teste = ft_printf("\n%u",tst);
	// ft_printf("\n%i", teste);
}
