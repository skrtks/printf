#include "printf.h"
#include "./libft/libft.h"
#include <stdio.h>
#include <unistd.h>


int main(void)
{
	write(1, "ft_printf:\n", 11);
	ft_printf("[test run %c]", 'x');
	printf("\n");

	printf("printf:\n");
	printf("[test run %8c]", 'x');
	printf("\n");
	return (0);
}