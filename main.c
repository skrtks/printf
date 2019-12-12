#include "printf.h"
#include "./libft/libft.h"
#include <stdio.h>
#include <unistd.h>


int main(void)
{

	// MARK: C-conversion
	ft_printf("[m: [test run %c]]\n", 'x');
	printf("[s: [test run %c]]\n", 'x');

	ft_printf("[m: [test run %5c]]\n", 'x');
	printf("[s: [test run %5c]]\n", 'x');

	ft_printf("[m: [test run %*c]]\n", 4, 'x');
	printf("[s: [test run %*c]]\n", 4, 'x');

	ft_printf("[m: [test run %-4c]]\n", 'x');
	printf("[s: [test run %-4c]]\n", 'x');

	ft_printf("[m: [test run %5c and another one %c]]\n", 'x', 'h');
	printf("[s: [test run %5c and another one %c]]\n", 'x', 'h');
	return (0);
}