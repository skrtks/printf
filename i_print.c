/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   i_print.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: skorteka <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 14:47:14 by skorteka      #+#    #+#                 */
/*   Updated: 2019/12/17 14:47:16 by skorteka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"
#include <stdarg.h>
#include <unistd.h>

/* 
1. If 0 flag && width > len && width > prec then sign is printed in width. 
2. Else if !0 flag && prec > len then sign is printed before prec 0's.
3. If !0 flag && prec <= len then sign is printed before len.
*/



static int	int_length(long n)
{
	long	len;

	len = 0;
	if (n < 0)
		n = n * -1;
	while (n >= 1)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char get_sign(int num)
{
	if (num < 0)
		return('-');
	else
		return('+');
}

static t_length get_length(t_flags flags, long num)
{
	t_length len;
	len.sign = get_sign(num);
	len.numlen = int_length(num);
	len.p_padlen = ((flags.prec != -1 && flags.prec >= len.numlen) ? flags.prec - len.numlen : 0);
	len.p_numlen = len.numlen + len.p_padlen;
	len.t_numlen = (len.sign == '-' ? len.p_numlen + 1 : len.p_numlen);
	len.w_padlen = ((flags.width != -1 && flags.width >= len.t_numlen) ? flags.width - len.t_numlen : 0);
	len.total_len = len.t_numlen + len.w_padlen;	
	return (len);
}

static int create_string(t_flags flags, t_length len, long num)
{
	char *str;

	str = 
}

int	i_print(va_list args, t_flags flags)
{
	long num;
	t_length len;
	
	num = (long)va_arg(args, int);
	len = get_length(flags, num);
	return (0);
}