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

int		int_length(long n)
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

char	*set_case(char *str, t_flags flags)
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

int		set_string(char **dst, char *src, int i)
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

t_flags	init_flags(void)
{
	t_flags flags;

	flags.minus = -1;
	flags.zero = -1;
	flags.hash = -1;
	flags.apo = -1;
	flags.space = -1;
	flags.plus = -1;
	flags.width = -1;
	flags.prec = -1;
	flags.conv = 'q';
	return (flags);
}

size_t	get_index(const char *str, char c)
{
	size_t l;

	l = 0;
	while (str[l] != '\0' && str[l] != c)
		l++;
	return (l);
}
