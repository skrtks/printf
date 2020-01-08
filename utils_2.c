/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: skorteka <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 12:32:29 by skorteka      #+#    #+#                 */
/*   Updated: 2020/01/07 12:32:30 by skorteka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"
#include <stdarg.h>

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
	flags.l_mod = 0;
	flags.conv = 'q';
	return (flags);
}

t_flags	parse_l_mod(const char **format, t_flags flags)
{
	while (ft_strrchr("lh", *(*format)))
	{
		if (*(*format) == 'l')
			flags.l_mod += 1;
		if (*(*format) == 'h')
			flags.l_mod += 3;
		(*format)++;
	}
	flags.conv = *(*format);
	return (flags);
}

// t_flags get_star(t_flags flags, va_list args, char *format)
// {
// 	int temp;

// 	if (*(*format) == '*')
// 	{
// 		temp = va_arg(args, int);
// 		if (temp < 0)
// 		{
// 			flags->minus = 1;
// 			flags->width = temp * -1;
// 		}
// 		else
// 			flags->width = temp;
// 	}
// 	return (format);
// }
