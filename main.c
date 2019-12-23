#include "printf.h"
#include "./libft/libft.h"
#include <stdio.h>
#include <unistd.h>

int main(void)
{

	ft_printf("m %%\n");
	printf("s %%\n");
	ft_printf("m %5%\n");
	printf("s %5%\n");
	ft_printf("m %.5%\n");
	printf("s %.5%\n");


	// int n = 399;
 //    int y = 0xABCDEF;


    // /* Upper and lower case. */

    // ft_printf ("m %X hexadecimal with upper case letters.\n", n);
    // printf ("s %X hexadecimal with upper case letters.\n", n);

    // ft_printf ("m %x hexadecimal with lower case letters.\n", n);
    // printf ("s %x hexadecimal with lower case letters.\n", n);


    // /* Different kinds of padding. */

    // ft_printf ("m <%8x> hexadecimal padded with blanks to width 8.\n", n);
    // printf ("s <%8x> hexadecimal padded with blanks to width 8.\n", n);

    // ft_printf ("m %04x hexadecimal padded with four leading zeros.\n", n);
    // printf ("s %04x hexadecimal padded with four leading zeros.\n", n);

    // ft_printf ("m %08x padded with eight leading zeros.\n", n);
    // printf ("s %08x padded with eight leading zeros.\n", n);


    //  Hash mark, #, adds 0x to number. 

    // ft_printf ("m %#x automatically add 0x.\n", y);
    // printf ("s %#x automatically add 0x.\n", y);

    // ft_printf ("m %#X, capital X, automatically add 0X.\n", y);
    // printf ("s %#X, capital X, automatically add 0X.\n", y);

    // ft_printf ("m %#X, but don't add 0X if zero.\n", 0);
    // printf ("s %#X, but don't add 0X if zero.\n", 0);


    // /* Hash mark plus padding. */

    // ft_printf ("m %#8x - no padding is added with #.\n", y);
    // printf ("s %#8x - no padding is added with #.\n", y);

    // ft_printf ("m %#8X - no padding is added with #.\n", y);
    // printf ("s %#8X - no padding is added with #.\n", y);

    // ft_printf ("m %#08X - padding is added with 0, but don't add 0X.\n", 0);
    // printf ("s %#08X - padding is added with 0, but don't add 0X.\n", 0);

	return (0);
}