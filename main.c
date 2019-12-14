#include "printf.h"
#include "./libft/libft.h"
#include <stdio.h>
#include <unistd.h>


int main(void)
{
	printf("%i\n", ft_printf("[s: [%6s]]\n", "test"));
	printf("%i\n", printf("[s: [%6s]]\n", "test"));

	printf("%i\n", ft_printf("[s: [%2.6s]]\n", "test"));
	printf("%i\n", printf("[s: [%2.6s]]\n", "test"));

	printf("%i\n", ft_printf("[s: [%.s]]\n", "test"));
	printf("%i\n", printf("[s: [%.s]]\n", "test"));

	printf("%i\n", ft_printf("[s: [%2.2s]]\n", "test"));
	printf("%i\n", printf("[s: [%2.2s]]\n", "test"));
	return (0);
}