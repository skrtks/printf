#include "printf.h"
#include "./libft/libft.h"
#include <stdio.h>
#include <unistd.h>


int main(void)
{
	ft_printf("[m: [this % i number]]\n", -267);
	printf("[s: [this % i number]]\n", -267);
	printf("---\n");

	ft_printf("[m: [%+-5.i]]\n", 0);
	printf("[s: [%+-5.i]]\n", 0);
	printf("---\n");

	ft_printf("[m: [%.i]]\n", 0);
	printf("[s: [%.i]]\n", 0);
	printf("---\n");

	ft_printf("[m: [%+5.i]]\n", 0);
	printf("[s: [%+5.i]]\n", 0);
	printf("---\n");

	ft_printf("[m: [%3i]]\n", 0);
	printf("[s: [%3i]]\n", 0);
	printf("---\n");

	ft_printf("[m: [%i]\n", 5);
	printf("[s: [%i]\n", 5);
	printf("---\n");

	ft_printf("[m: [%i]\n", 5);
	printf("[s: [%i]\n", 5);
	printf("---\n");

	ft_printf("[m: [%.2i]]\n", -12);
	printf("[s: [%.2i]]\n", -12);
	printf("---\n");

	ft_printf("[m: [%2i]]\n", -12);
	printf("[s: [%2i]]\n", -12);
	printf("---\n");

	ft_printf("[m: [%.2i]]\n", 12);
	printf("[s: [%.2i]]\n", 12);
	printf("---\n");

	ft_printf("[m: [%1i]]\n", 12);
	printf("[s: [%1i]]\n", 12);
	printf("---\n");

	ft_printf("[m: [%1i]]\n", 12);
	printf("[s: [%1i]]\n", 12);
	printf("---\n");

	ft_printf("[m: [%.4i]]\n", 12);
	printf("[s: [%.4i]]\n", 12);
	printf("---\n");

	ft_printf("[m: [%.4i]]\n", 12);
	printf("[s: [%.4i]]\n", 12);
	printf("---\n");

	ft_printf("[m: [%4i]]\n", 12);
	printf("[s: [%4i]]\n", 12);
	printf("---\n");

	ft_printf("[m: [%4i]]\n", -12);
	printf("[s: [%4i]]\n", -12);
	printf("---\n");

	ft_printf("[m: [%4.4i]]\n", 12);
	printf("[s: [%4.4i]]\n", 12);
	printf("---\n");

	ft_printf("[m: [%4.4i]]\n", 12);
	printf("[s: [%4.4i]]\n", 12);
	printf("---\n");

	ft_printf("[m: [%4.4i]]\n", 12);
	printf("[s: [%4.4i]]\n", 12);
	printf("---\n");

	ft_printf("[m: [%4.4i]]\n", -12);
	printf("[s: [%4.4i]]\n", -12);
	printf("---\n");

	ft_printf("[m: [%-3.4i]]\n", 12);
	printf("[s: [%-3.4i]]\n", 12);
	printf("---\n");

	ft_printf("[m: [%-4.3i]]\n", 12);
	printf("[s: [%-4.3i]]\n", 12);
	printf("---\n");

	ft_printf("[m: [%07i]]\n", -54);
	printf("[s: [%07i]]\n", -54);
	printf("---\n");

	ft_printf("[m: [%8.5i]]\n", 34);
	printf("[s: [%8.5i]]\n", 34);
	printf("---\n");

	ft_printf("[m: [%05i]]\n", 234);
	printf("[s: [%05i]]\n", 234);
	printf("---\n");

	ft_printf("[m: [%10.5i]]\n", -216);
	printf("[s: [%10.5i]]\n", -216);
	printf("---\n");

	return (0);
}