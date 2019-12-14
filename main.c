#include "printf.h"
#include "./libft/libft.h"
#include <stdio.h>
#include <unistd.h>


int main(void)
{
	printf("%i", ft_printf("[s: [%s]]\n", "test"));
	return (0);
}