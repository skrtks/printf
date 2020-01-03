#include "printf.h"
#include "./libft/libft.h"
#include <stdio.h>
#include <unistd.h>

static void print_out(int i)
{
	ft_putnbr_fd(i, 1);
	write(1, "\n", 1);
}

int main(void)
{
    char *test = "test";
	ft_printf("test int %p \n", test);
    printf("test int %p \n", test);

    ft_printf("test int %u \n", 123);
    printf("test int %u \n", 123);


	int n = 399;
    int y = 0xABCDEF;

    // /* Upper and lower case. */

    ft_printf ("m %X hexadecimal with upper case letters.\n", n);
    printf ("s %X hexadecimal with upper case letters.\n", n);

    ft_printf ("m %x hexadecimal with lower case letters.\n", n);
    printf ("s %x hexadecimal with lower case letters.\n", n);


    // /* Different kinds of padding. */

    ft_printf ("m <%8x> hexadecimal padded with blanks to width 8.\n", n);
    printf ("s <%8x> hexadecimal padded with blanks to width 8.\n", n);

    ft_printf ("m %04x hexadecimal padded with four leading zeros.\n", n);
    printf ("s %04x hexadecimal padded with four leading zeros.\n", n);

    ft_printf ("m %08x padded with eight leading zeros.\n", n);
    printf ("s %08x padded with eight leading zeros.\n", n);


    // /* Hash mark, #, adds 0x to number. */

    ft_printf ("m %#x automatically add 0x.\n", y);
    printf ("s %#x automatically add 0x.\n", y);

    ft_printf ("m %#X, capital X, automatically add 0X.\n", y);
    printf ("s %#X, capital X, automatically add 0X.\n", y);

    ft_printf ("m %#X, but don't add 0X if zero.\n", 0);
    printf ("s %#X, but don't add 0X if zero.\n", 0);


    /* Hash mark plus padding. */

    ft_printf ("m [%#.0x] - #.0x\n", 0);
    printf ("s [%#.0x] - #.0x\n", 0);

    ft_printf ("m [%#4x] - #4x\n", 52625);
    printf ("s [%#4x] - #4x\n", 52625);

    ft_printf ("m [%#5x] - #5x\n", 52625);
    printf ("s [%#5x] - #5x\n", 52625);

    ft_printf ("m [%#6x] - #6x\n", 52625);
    printf ("s [%#6x] - #6x\n", 52625);

    ft_printf ("m [%#7x] - #7x\n", 52625);
    printf ("s [%#7x] - #7x\n", 52625);

    ft_printf ("m [%#-7x] - #-7x\n", 52625);
    printf ("s [%#-7x] - #-7x\n", 52625);

    ft_printf ("m [%#.5x] - #.5x\n", 52625);
    printf ("s [%#.5x] - #.5x\n", 52625);

    ft_printf ("m %#10x - #10x\n", y);
    printf ("s %#10x - #10x\n", y);

    ft_printf ("m %#010x - #010\n", y);
    printf ("s %#010x - #010\n", y);

    ft_printf ("m %#10.10x - #10.10\n", y);
    printf ("s %#10.10x - #10.10\n", y);

    ft_printf ("m %#.10x - no prec? is added with #.\n", y);
    printf ("s %#.10x - no prec? is added with #.\n", y);

    ft_printf ("m %#8x - no padding is added with #.\n", y);
    printf ("s %#8x - no padding is added with #.\n", y);

    ft_printf ("m %#8X - no padding is added with #.\n", y);
    printf ("s %#8X - no padding is added with #.\n", y);

    ft_printf ("m %#08X - padding is added with 0, but don't add 0X.\n", 0);
    printf ("s %#08X - padding is added with 0, but don't add 0X.\n", 0);

    // MARK: pointer tests
    char *s;

    s = "test";

    ft_printf("m: %p\n", NULL);
    printf("s: %p\n", NULL);

    ft_printf ("m [%4p] - 4p\n", s);
    printf ("s [%4p] - 4p\n", s);

    ft_printf ("m [%5p] - 5p\n", s);
    printf ("s [%5p] - 5p\n", s);

    ft_printf ("m [%6p] - 6p\n", s);
    printf ("s [%6p] - 6p\n", s);

    ft_printf ("m [%7p] - 7p\n", s);
    printf ("s [%7p] - 7p\n", s);

    ft_printf ("m [%-7p] - -7p\n", s);
    printf ("s [%-7p] - -7p\n", s);

    ft_printf ("m [%30p] - 30p\n", s);
    printf ("s [%30p] - 30p\n", s);

    ft_printf ("m [%-30p] - -30p\n", s);
    printf ("s [%-30p] - -30p\n", s);

    // MARK c
	print_out(ft_printf("[s: [test run %c]]\n", 'x'));
	print_out(ft_printf("[s: [test run %5c]]\n", 'x'));
	print_out(ft_printf("[s: [test run %*c]]\n", 4, 'x'));
	print_out(ft_printf("[s: [test run %-4c]]\n", 'x'));
	print_out(ft_printf("[s: [test run %5c and another one %c]]\n", 'x', 'h'));
	print_out(ft_printf("[s: [%c%c%c%c%c]]\n", 'x', 'h', 's', 'w', 'q'));
	print_out(ft_printf("[s: [test run %5c and another one %c]]\n", 'x', 'h'));

	// MARK s
	print_out(ft_printf("[s: [%s]]\n", "3abc!\012@#$%^&*(_)(*_-±§	"));
	print_out(ft_printf("[s: [%.0s]]\n", "3abc!\012@#$%^&*(_)(*_-±§	"));
	print_out(ft_printf("[s: [%2.5s]]\n", "3abc!\012@#$%^&*(_)(*_-±§	"));
	print_out(ft_printf("[s: [%3.3s]]\n", "3abc!\012@#$%^&*(_)(*_-±§	"));
	print_out(ft_printf("[s: [%2.3s]]\n", "3abc!\012@#$%^&*(_)(*_-±§	"));
	print_out(ft_printf("[s: [%2.10s]]\n", "3abc!\012@#$%^&*(_)(*_-±§	"));
	print_out(ft_printf("[s: [%8.6s]]\n", "3abc!\012@#$%^&*(_)(*_-±§	"));
	print_out(ft_printf("[s: [%-s]]\n", "3abc!\012@#$%^&*(_)(*_-±§	"));
	print_out(ft_printf("[s: [%-.0s]]\n", "3abc!\012@#$%^&*(_)(*_-±§	"));
	print_out(ft_printf("[s: [%-2.5s]]\n", "3abc!\012@#$%^&*(_)(*_-±§	"));
	
	print_out(ft_printf("[s: [%-3.3s]]\n", "3abc!\012@#$%^&*(_)(*_-±§	"));
	print_out(ft_printf("[s: [%-2.3s]]\n", "3abc!\012@#$%^&*(_)(*_-±§	"));
	print_out(ft_printf("[s: [%-2.10s]]\n", "3abc!\012@#$%^&*(_)(*_-±§	"));
	print_out(ft_printf("[s: [%-1.6s]]\n", "3abc!\012@#$%^&*(_)(*_-±§	"));
	print_out(ft_printf("[s: [%-2.6s]]\n", "3abc!\012@#$%^&*(_)(*_-±§	"));
	print_out(ft_printf("[s: [%-3.6s]]\n", "3abc!\012@#$%^&*(_)(*_-±§	"));
	print_out(ft_printf("[s: [%-4.6s]]\n", "3abc!\012@#$%^&*(_)(*_-±§	"));
	print_out(ft_printf("[s: [%-5.6s]]\n", "3abc!\012@#$%^&*(_)(*_-±§	"));
	print_out(ft_printf("[s: [%-6.6s]]\n", "3abc!\012@#$%^&*(_)(*_-±§	"));
	print_out(ft_printf("[s: [%-6s]]\n", "3abc!\012@#$%^&*(_)(*_-±§ "));
	
	print_out(ft_printf("[s: [%-.6s]]\n", "3abc!\012@#$%^&*(_)(*_-±§ "));
	print_out(ft_printf("[s: [%-6.6s]]\n", "3abc!\012@#$%^&*(_)(*_-±§ "));
	print_out(ft_printf("[s: [%-7.6s]]\n", "3abc!\n@#$%^&*(_)(*_-±§ "));
	print_out(ft_printf("[s: [%-8.6s]]\n", "3abc!\012@#$%^&*(_)(*_-±§	"));
	print_out(ft_printf("[s: [%8.3s]]\n", "3abc!\012@#$%^&*(_)(*_-±§	"));
	print_out(ft_printf("[s: [%8.0s]]\n", "3abc!\012@#$%^&*(_)(*_-±§	"));
	print_out(ft_printf("[s: [%8s]]\n", "hal\0lo"));
	print_out(ft_printf("[s: [%s%s%s%s]]\n", "3abc!\012@#$%^&*(_)(*_-±§	", "world", "test", "dit"));
	print_out(ft_printf("[s: [%8.0s]]\n", ""));
	print_out(ft_printf("[s: [%s]]\n", ""));
	
	print_out(ft_printf("[s: [%s]]\n", ""));
	print_out(ft_printf("[s: [%5s]]\n", "goes over"));
	print_out(ft_printf("[s: [%-32s]]\n", "abc"));
	print_out(ft_printf("[s: [%.s]]\n", "hello"));
	print_out(ft_printf("[s: [%7.7s%7.7s]]\n", "hello", "world"));
	print_out(ft_printf("[s: [%s]]\n", NULL));
	print_out(ft_printf("[s: [%.s]]\n", NULL));
	print_out(ft_printf("[s: [%0.1s]]\n", NULL));
	print_out(ft_printf("[s: [%1.1s]]\n", NULL));
	print_out(ft_printf("[s: [%2.5s]]\n", NULL));
	
	print_out(ft_printf("[s: [%5.2s]]\n", NULL));
	print_out(ft_printf("[s: [%.6s]]\n", NULL));
	print_out(ft_printf("[s: [%1.3s%4.8s]]\n", NULL, NULL));
	print_out(ft_printf("[s: [%0.1s%4.8s]]\n", NULL, NULL));
	print_out(ft_printf("[s: [%.1s%4.8s]]\n", NULL, NULL));
	print_out(ft_printf("[s: [%3.6s]]\n", "\0"));

	// MARK i
	print_out(ft_printf("[s: [%i]]\n", 12));
	print_out(ft_printf("[s: [%.4i]]\n", 12));
	print_out(ft_printf("[s: [%4i]]\n", 12));
	print_out(ft_printf("[s: [%4.4i]]\n", 12));
	print_out(ft_printf("[s: [%3.4i]]\n", 12));
	print_out(ft_printf("[s: [%4.3i]]\n", 12));
	
	print_out(ft_printf("[s: [%0i]]\n", 12));
	print_out(ft_printf("[s: [%0.4i]]\n", 12));
	print_out(ft_printf("[s: [%04i]]\n", 12));
	print_out(ft_printf("[s: [%04.4i]]\n", 12));
	print_out(ft_printf("[s: [%03.4i]]\n", 12));
	print_out(ft_printf("[s: [%04.3i]]\n", 12));
	
	print_out(ft_printf("[s: [%-i]]\n", 12));
	print_out(ft_printf("[s: [%-.4i]]\n", 12));
	print_out(ft_printf("[s: [%-4i]]\n", 12));
	print_out(ft_printf("[s: [%-4.4i]]\n", 12));
	print_out(ft_printf("[s: [%-3.4i]]\n", 12));
	print_out(ft_printf("[s: [%-4.3i]]\n", 12));

	print_out(ft_printf("[s: [this % i number]]\n", -267));
	print_out(ft_printf("[s: [%+-5.i]]\n", 0));
	print_out(ft_printf("[s: [%.i]]\n", 0));
	print_out(ft_printf("[s: [%+5.i]]\n", 0));
	print_out(ft_printf("[s: [%3i]]\n", 0));
	print_out(ft_printf("[s: [%i]\n", 5));
	print_out(ft_printf("[s: [%i]\n", 5));
	print_out(ft_printf("[s: [%.2i]]\n", -12));
	print_out(ft_printf("[s: [%2i]]\n", -12));
	print_out(ft_printf("[s: [%.2i]]\n", 12));
	print_out(ft_printf("[s: [%1i]]\n", 12));
	print_out(ft_printf("[s: [%1i]]\n", 12));
	print_out(ft_printf("[s: [%.4i]]\n", 12));
	print_out(ft_printf("[s: [%.4i]]\n", 12));
	print_out(ft_printf("[s: [%4i]]\n", 12));
	print_out(ft_printf("[s: [%4i]]\n", -12));
	print_out(ft_printf("[s: [%4.4i]]\n", 12));
	print_out(ft_printf("[s: [%4.4i]]\n", 12));
	print_out(ft_printf("[s: [%4.4i]]\n", 12));
	print_out(ft_printf("[s: [%4.4i]]\n", -12));
	print_out(ft_printf("[s: [%-3.4i]]\n", 12));
	print_out(ft_printf("[s: [%-4.3i]]\n", 12));
	print_out(ft_printf("[s: [%07i]]\n", -54));
	print_out(ft_printf("[s: [%8.5i]]\n", 34));
	print_out(ft_printf("[s: [%05i]]\n", 234));
	print_out(ft_printf("[s: [%10.5i]]\n", -216));

	// MARK u
	ft_printf("[s: [this %u number]]\n", -267);
	ft_printf("[s: [%5.u]]\n", 0);
	ft_printf("[s: [%.u]]\n", 0);
	ft_printf("[s: [%5.u]]\n", 0);
	ft_printf("[s: [%3u]]\n", 0);
	ft_printf("[s: [%u]\n", 5);
	ft_printf("[s: [%u]\n", 5);
	ft_printf("[s: [%.2u]]\n", -12);
	ft_printf("[s: [%2u]]\n", -12);
	ft_printf("[s: [%.2u]]\n", 12);
	ft_printf("[s: [%1u]]\n", 12);
	ft_printf("[s: [%1u]]\n", 12);
	ft_printf("[s: [%.4u]]\n", 12);
	ft_printf("[s: [%.4u]]\n", 12);
	ft_printf("[s: [%4u]]\n", 12);
	ft_printf("[s: [%4u]]\n", -12);
	ft_printf("[s: [%4.4u]]\n", 12);
	ft_printf("[s: [%4.4u]]\n", 12);
	ft_printf("[s: [%4.4u]]\n", 12);
	ft_printf("[s: [%4.4u]]\n", -12);
	ft_printf("[s: [%-3.4u]]\n", 12);
	ft_printf("[s: [%-4.3u]]\n", 12);
	ft_printf("[s: [%07u]]\n", -54);
	ft_printf("[s: [%8.5u]]\n", 34);
	ft_printf("[s: [%05u]]\n", 234);
	ft_printf("[s: [%10.5u]]\n", -216);

    //MARK: percentage tests
    // ft_printf ("m %-04%\n");
    // printf ("s %-04%\n");

	return (0);
}