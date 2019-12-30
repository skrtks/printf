#include "printf.h"
#include "./libft/libft.h"
#include <stdio.h>
#include <unistd.h>

int main(void)
{

	


	// int n = 399;
    // int y = 0xABCDEF;


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


    // /* Hash mark, #, adds 0x to number. */

    // ft_printf ("m %#x automatically add 0x.\n", y);
    // printf ("s %#x automatically add 0x.\n", y);

    // ft_printf ("m %#X, capital X, automatically add 0X.\n", y);
    // printf ("s %#X, capital X, automatically add 0X.\n", y);

    // ft_printf ("m %#X, but don't add 0X if zero.\n", 0);
    // printf ("s %#X, but don't add 0X if zero.\n", 0);


    /* Hash mark plus padding. */

    // ft_printf ("m [%#.0x] - #.0x\n", 0);
    // printf ("s [%#.0x] - #.0x\n", 0);

    // ft_printf ("m [%#4x] - #4x\n", 52625);
    // printf ("s [%#4x] - #4x\n", 52625);

    // ft_printf ("m [%#5x] - #5x\n", 52625);
    // printf ("s [%#5x] - #5x\n", 52625);

    // ft_printf ("m [%#6x] - #6x\n", 52625);
    // printf ("s [%#6x] - #6x\n", 52625);

    // ft_printf ("m [%#7x] - #7x\n", 52625);
    // printf ("s [%#7x] - #7x\n", 52625);

    ft_printf ("m [%#-7x] - #-7x\n", 52625);
    printf ("s [%#-7x] - #-7x\n", 52625);

    ft_printf ("m [%#.5x] - #.5x\n", 52625);
    printf ("s [%#.5x] - #.5x\n", 52625);

    // ft_printf ("m %#10x - #10x\n", y);
    // printf ("s %#10x - #10x\n", y);

    // ft_printf ("m %#010x - #010\n", y);
    // printf ("s %#010x - #010\n", y);

    // ft_printf ("m %#10.10x - #10.10\n", y);
    // printf ("s %#10.10x - #10.10\n", y);

    // ft_printf ("m %#.10x - no prec? is added with #.\n", y);
    // printf ("s %#.10x - no prec? is added with #.\n", y);

    // ft_printf ("m %#8x - no padding is added with #.\n", y);
    // printf ("s %#8x - no padding is added with #.\n", y);

    // ft_printf ("m %#8X - no padding is added with #.\n", y);
    // printf ("s %#8X - no padding is added with #.\n", y);

    // ft_printf ("m %#08X - padding is added with 0, but don't add 0X.\n", 0);
    // printf ("s %#08X - padding is added with 0, but don't add 0X.\n", 0);

	return (0);
}