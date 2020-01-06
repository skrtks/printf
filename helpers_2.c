/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers_2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: skorteka <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 15:48:44 by skorteka      #+#    #+#                 */
/*   Updated: 2020/01/06 15:48:46 by skorteka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"
#include <stdarg.h>
#include <locale.h>

int sep_calculator(long num)
{
	unsigned int	len;

	len = 0;
	if (num < 0)
		num *= -1;
	while (num >= 1000)
	{
		num = num / 1000;
		len++;
	}
	return (len);
}

char *set_separators(long num, t_length len, char *str, int start)
{
	int i;
	struct lconv * lc;

	lc = localeconv();
	i = start + len.numlen;
	if (num < 0)
		num *= -1;
	while (num >= 1000)
	{
		i -= 4;
		str[i] = *lc->thousands_sep;
		num /= 1000;
	}
	return (str);
}
