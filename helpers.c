/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: skorteka <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/23 13:26:26 by skorteka      #+#    #+#                 */
/*   Updated: 2019/12/23 13:26:28 by skorteka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"
#include <stdarg.h>

int			int_length(long n)
{
	long	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = n * -1;
	while (n >= 1)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*set_case(char *str, t_flags flags)
{
	int i;

	i = 0;
	while (str[i] && flags.conv == 'X')
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	while (str[i] && flags.conv == 'x')
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

int			set_string(char **dst, char *src, int i)
{
	int j;

	j = 0;
	while (src[j])
	{
		*(*dst + i) = src[j];
		i++;
		j++;
	}
	return (i);
}

size_t		get_index(const char *str, char c)
{
	size_t l;

	l = 0;
	while (str[l] != '\0' && str[l] != c)
		l++;
	return (l);
}

long long	get_dec(t_flags flags, va_list args)
{
	long long num;

	if (flags.l_mod == 1 && (flags.conv == 'i' || flags.conv == 'd'))
		num = (long)va_arg(args, long);
	else if (flags.l_mod == 2 && (flags.conv == 'i' || flags.conv == 'd'))
		num = (long long)va_arg(args, long long);
	else if (flags.l_mod == 3 && (flags.conv == 'i' || flags.conv == 'd'))
		num = (short)va_arg(args, void*);
	else if (flags.l_mod == 6 && (flags.conv == 'i' || flags.conv == 'd'))
		num = (signed char)va_arg(args, void*);
	else if (flags.conv == 'i' || flags.conv == 'd')
		num = (long long)va_arg(args, int);
	else if (flags.l_mod == 1 && (flags.conv != 'i' || flags.conv != 'd'))
		num = (unsigned long)va_arg(args, unsigned long);
	else if (flags.l_mod == 2 && (flags.conv != 'i' || flags.conv != 'd'))
		num = (unsigned long long)va_arg(args, unsigned long long);
	else if (flags.l_mod == 3 && (flags.conv != 'i' || flags.conv != 'd'))
		num = (unsigned short)va_arg(args, void*);
	else if (flags.l_mod == 6 && (flags.conv != 'i' || flags.conv != 'd'))
		num = (unsigned char)va_arg(args, void*);
	else
		num = (unsigned long long)va_arg(args, unsigned int);
	return (num);
}
