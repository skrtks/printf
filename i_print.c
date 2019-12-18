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

static char get_sign(int num)
{
	if (num < 0)
		return('-');
	else
		return('+');
}

int	i_print(va_list args, t_flags flags)
{
	char sign;
	char *str;
	int num;
	int len;

	num = va_arg(args, int);
	str = ft_itoa(num);
	len = ft_strlen(str);
	sign = get_sign(num);
	if (flags.width <= len && flags.prec <= len)
	{
		if (flags.plus == 1 && sign == '+' && str[0] != '+')
			ft_putchar_fd(sign, 1);
		write(1, str, len);
	}
	

	return (0);
}