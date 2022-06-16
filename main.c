#include "ft_printf.h"
#include <stdio.h>




int main()
{
	int num_dec = 0;
	int mod = 1000 / 16;
	mod  %= 16;

	printf("\n%p\n",&num_dec);
	ft_printf("%p\n",&num_dec);


}

