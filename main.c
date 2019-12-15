#include "printf.h"
#include "./libft/libft.h"
#include <stdio.h>
#include <unistd.h>


int main(void)
{
	printf("%i\n", printf("[s: [%-8.6s]]\n", "3abc!\012@#$%^&*(_)(*_-±§	"));
	printf("%i\n", ft_printf("[s: [%-8.6s]]\n", "3abc!\012@#$%^&*(_)(*_-±§	"));
	return (0);
}