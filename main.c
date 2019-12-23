#include "printf.h"
#include "./libft/libft.h"
#include <stdio.h>
#include <unistd.h>

int main(void)
{

	printf("Test %s\n", ft_itoa_base(0, 10));
	// ft_printf("[m: [this % i number]]\n", -267);
	// printf("[s: [this % i number]]\n", -267);
	// printf("---\n");

	// ft_printf("[m: [%+-5.i]]\n", 0);
	// printf("[s: [%+-5.i]]\n", 0);
	// printf("---\n");

	// ft_printf("[m: [%.i]]\n", 0);
	// printf("[s: [%.i]]\n", 0);
	// printf("---\n");

	// ft_printf("[m: [%+5.i]]\n", 0);
	// printf("[s: [%+5.i]]\n", 0);
	// printf("---\n");

	// ft_printf("[m: [%3i]]\n", 0);
	// printf("[s: [%3i]]\n", 0);
	// printf("---\n");

	// ft_printf("[m: [%i]\n", 5);
	// printf("[s: [%i]\n", 5);
	// printf("---\n");

	// ft_printf("[m: [%i]\n", 5);
	// printf("[s: [%i]\n", 5);
	// printf("---\n");

	// ft_printf("[m: [%.2i]]\n", -12);
	// printf("[s: [%.2i]]\n", -12);
	// printf("---\n");

	// ft_printf("[m: [%2i]]\n", -12);
	// printf("[s: [%2i]]\n", -12);
	// printf("---\n");

	// ft_printf("[m: [%.2i]]\n", 12);
	// printf("[s: [%.2i]]\n", 12);
	// printf("---\n");

	// ft_printf("[m: [%1i]]\n", 12);
	// printf("[s: [%1i]]\n", 12);
	// printf("---\n");

	// ft_printf("[m: [%1i]]\n", 12);
	// printf("[s: [%1i]]\n", 12);
	// printf("---\n");

	// ft_printf("[m: [%.4i]]\n", 12);
	// printf("[s: [%.4i]]\n", 12);
	// printf("---\n");

	// ft_printf("[m: [%.4i]]\n", 12);
	// printf("[s: [%.4i]]\n", 12);
	// printf("---\n");

	// ft_printf("[m: [%4i]]\n", 12);
	// printf("[s: [%4i]]\n", 12);
	// printf("---\n");

	// ft_printf("[m: [%4i]]\n", -12);
	// printf("[s: [%4i]]\n", -12);
	// printf("---\n");

	// ft_printf("[m: [%4.4i]]\n", 12);
	// printf("[s: [%4.4i]]\n", 12);
	// printf("---\n");

	// ft_printf("[m: [%4.4i]]\n", 12);
	// printf("[s: [%4.4i]]\n", 12);
	// printf("---\n");

	// ft_printf("[m: [%4.4i]]\n", 12);
	// printf("[s: [%4.4i]]\n", 12);
	// printf("---\n");

	// ft_printf("[m: [%4.4i]]\n", -12);
	// printf("[s: [%4.4i]]\n", -12);
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

	// ft_printf("[m: [%8.5i]]\n", 34);
	// printf("[s: [%8.5i]]\n", 34);
	// printf("---\n");

	// ft_printf("[m: [%05i]]\n", 234);
	// printf("[s: [%05i]]\n", 234);
	// printf("---\n");

	// ft_printf("[m: [%10.5i]]\n", -216);
	// printf("[s: [%10.5i]]\n", -216);
	// printf("---\n");

	
	ft_printf("[m: [this %u number]]\n", -267);
	printf("[m: [this %u number]]\n", -267);
	
	ft_printf("[m: [%5.u]]\n", 0);
	printf("[m: [%5.u]]\n", 0);
	
	ft_printf("[m: [%.u]]\n", 0);
	printf("[m: [%.u]]\n", 0);
	
	ft_printf("[m: [%5.u]]\n", 0);
	printf("[m: [%5.u]]\n", 0);
	
	ft_printf("[m: [%3u]]\n", 0);
	printf("[m: [%3u]]\n", 0);
	
	ft_printf("[m: [%u]\n", 5);
	printf("[m: [%u]\n", 5);
	
	ft_printf("[m: [%u]\n", 5);
	printf("[m: [%u]\n", 5);
	
	ft_printf("[m: [%.2u]]\n", -12);
	printf("[m: [%.2u]]\n", -12);
	
	ft_printf("[m: [%2u]]\n", -12);
	printf("[m: [%2u]]\n", -12);
	
	ft_printf("[m: [%.2u]]\n", 12);
	printf("[m: [%.2u]]\n", 12);
	
	ft_printf("[m: [%1u]]\n", 12);
	printf("[m: [%1u]]\n", 12);
	
	ft_printf("[m: [%1u]]\n", 12);
	printf("[m: [%1u]]\n", 12);
	
	ft_printf("[m: [%.4u]]\n", 12);
	printf("[m: [%.4u]]\n", 12);
	
	ft_printf("[m: [%.4u]]\n", 12);
	printf("[m: [%.4u]]\n", 12);
	
	ft_printf("[m: [%4u]]\n", 12);
	printf("[m: [%4u]]\n", 12);
	
	ft_printf("[m: [%4u]]\n", -12);
	printf("[m: [%4u]]\n", -12);
	
	ft_printf("[m: [%4.4u]]\n", 12);
	printf("[m: [%4.4u]]\n", 12);
	
	ft_printf("[m: [%4.4u]]\n", 12);
	printf("[m: [%4.4u]]\n", 12);
	
	ft_printf("[m: [%4.4u]]\n", 12);
	printf("[m: [%4.4u]]\n", 12);
	
	ft_printf("[m: [%4.4u]]\n", -12);
	printf("[m: [%4.4u]]\n", -12);
	
	ft_printf("[m: [%-3.4u]]\n", 12);
	printf("[m: [%-3.4u]]\n", 12);
	
	ft_printf("[m: [%-4.3u]]\n", 12);
	printf("[m: [%-4.3u]]\n", 12);
	
	ft_printf("[m: [%07u]]\n", -54);
	printf("[m: [%07u]]\n", -54);
	
	ft_printf("[m: [%8.5u]]\n", 34);
	printf("[m: [%8.5u]]\n", 34);
	
	ft_printf("[m: [%05u]]\n", 234);
	printf("[m: [%05u]]\n", 234);

	return (0);
}