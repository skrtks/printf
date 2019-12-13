#include "printf.h"
#include "./libft/libft.h"
#include <stdio.h>
#include <unistd.h>


int main(void)
{
	//MARK c
	printf("\nMARK C\n");

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

	ft_printf("[m: [%c%c%c%c%c]]\n", 'x', 'h', 's', 'w', 'q');
	printf("[s: [%c%c%c%c%c]]\n", 'x', 'h', 's', 'w', 'q');

	ft_printf("[m: [test run %5c and another one %c]]\n", 'x', 'h');
	printf("[s: [test run %5c and another one %c]]\n", 'x', 'h');

	//MARK s
	printf("\nMARK S\n");

	ft_printf("[m: [%s]]\n", "hallo");
	printf("[s: [%s]]\n", "hallo");

	ft_printf("[m: [%.0s]]\n", "hallo");
	printf("[s: [%.0s]]\n", "hallo");

	ft_printf("[m: [%2.5s]]\n", "hallo");
	printf("[s: [%2.5s]]\n", "hallo");

	ft_printf("[m: [%3.3s]]\n", "hallo");
	printf("[s: [%3.3s]]\n", "hallo");

	ft_printf("[m: [%2.3s]]\n", "hallo");
	printf("[s: [%2.3s]]\n", "hallo");

	ft_printf("[m: [%2.10s]]\n", "hallo");
	printf("[s: [%2.10s]]\n", "hallo");

	ft_printf("[m: [%8.6s]]\n", "hallo");
	printf("[s: [%8.6s]]\n", "hallo");

	ft_printf("[m: [%-8.6s]]\n", "hallo");
	printf("[s: [%-8.6s]]\n", "hallo");

	ft_printf("[m: [%8.3s]]\n", "hallo");
	printf("[s: [%8.3s]]\n", "hallo");

	ft_printf("[m: [%8.0s]]\n", "hallo");
	printf("[s: [%8.0s]]\n", "hallo");

	ft_printf("[m: [%8s]]\n", "hallo");
	printf("[s: [%8s]]\n", "hallo");

	return (0);
}