/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: skorteka <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 11:39:11 by skorteka      #+#    #+#                 */
/*   Updated: 2019/11/01 11:39:12 by skorteka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdlib.h>

static size_t	ft_length(long long n)
{
	long long	len;

	if (n > 0)
		len = 0;
	else
	{
		len = 1;
		n = n * -1;
	}
	while (n >= 1)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa_base(long long value, int base)
{
	char 		*set;
    char    	*ptr;
    long long	num;

    ptr = malloc((ft_length(value) + 1) * sizeof(char));
	set =  "0123456789abcdef";
    *ptr = '\0';
    num = value;
    if (value < 0 && base == 10)
        value *= -1;
    if (value == 0)
	{
		ptr--;
		*ptr = set[value % base];
	}
    while (value > 0)
    {
		ptr--;
        *ptr = set[value % base];
        value /= base;
    }
    if (num < 0 && base == 10)
	{
		ptr--;
        *ptr = '-';
	}
	return (ptr);
}
