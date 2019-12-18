#include "printf.h"
#include "./libft/libft.h"
#include <stdio.h>
#include <unistd.h>


int main(void)
{
	// ft_printf("[m: [%04i]]\n", -532);
	// printf("[s: [%04i]]\n", -532);
	// printf("---\n");

	// ft_printf("[m: [%+i]\n", 5);
	// printf("[s: [%+i]\n", 5);
	// printf("---\n");

	// ft_printf("[m: [%+i]\n", +5);
	// printf("[s: [%+i]\n", +5);
	// printf("---\n");

	ft_printf("[m: [%.2i]]\n", -12);
	printf("[s: [%.2i]]\n", -12);
	printf("---\n");

	ft_printf("[m: [%2i]]\n", -12);
	printf("[s: [%2i]]\n", -12);
	printf("---\n");

	ft_printf("[m: [%+.2i]]\n", 12);
	printf("[s: [%+.2i]]\n", 12);
	printf("---\n");

	ft_printf("[m: [%+1i]]\n", 12);
	printf("[s: [%+1i]]\n", 12);
	printf("---\n");

	ft_printf("[m: [%1i]]\n", 12);
	printf("[s: [%1i]]\n", 12);
	printf("---\n");

	// ft_printf("[m: [%+.4i]]\n", 12);
	// printf("[s: [%+.4i]]\n", 12);
	// printf("---\n");

	// ft_printf("[m: [%+3i]]\n", 12);
	// printf("[s: [%+3i]]\n", 12);
	// printf("---\n");

	// ft_printf("[m: [%+4i]]\n", 12);
	// printf("[s: [%+4i]]\n", 12);
	// printf("---\n");

	// ft_printf("[m: [%4i]]\n", -12);
	// printf("[s: [%4i]]\n", -12);
	// printf("---\n");

	// ft_printf("[m: [%-3.4i]]\n", 12);
	// printf("[s: [%-3.4i]]\n", 12);
	// printf("---\n");

	// ft_printf("[m: [%-4.3i]]\n", 12);
	// printf("[s: [%-4.3i]]\n", 12);
	// printf("---\n");

	// ft_printf("[m: [%07i]]\n", -54);
	// printf("[s: [%07i]]\n", -54);
	// printf("---\n");

	return (0);
}