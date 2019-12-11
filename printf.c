/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: skorteka <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 09:31:07 by skorteka      #+#    #+#                 */
/*   Updated: 2019/12/11 09:31:09 by skorteka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "printf.h"
#include "./libft/libft.h"
#include <unistd.h>


#include <stdio.h>

static void	convert(const char **format, va_list args, t_flags flags)
{
	if (*(*format) == 'c')
		c_print(args, flags);
	// if (*(*format) == 's')
	// 	s_print(args);
	(*format)++;
}

static t_flags	parse_flags(const char **format)
{
	t_flags flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.hash = 0;
	flags.apo = 0;
	flags.space = 0;
	flags.width = 0;
	flags.prec = 0;
	while (ft_strrchr("-0#\' +", *(*format)))
	{
		if (*(*format) == '-')
			flags.minus = 1;
		if (*(*format) == '0')
			flags.zero = 1;
		if (*(*format) == '#')
			flags.hash = 1;
		if (*(*format) == '\'')
			flags.apo = 1;
		if (*(*format) == ' ')
			flags.space = 1;
		if (*(*format) == '+')
			flags.plus = 1;
		(*format)++;
	}
	return (flags);
}

static void parse_other(const char **format, va_list args, t_flags *flags)
{
	if (*(*format) == '*')
		flags->width = va_arg(args, int);
	else if (!ft_strrchr("cspdiuxX%.", *(*format)))
		flags->width = ft_atoi(*format);
	while (!ft_strrchr("cspdiuxX%.", *(*format)))
		(*format)++;
	if (*(*format) == '.')
	{
		(*format)++;
		if (*(*format) == '*')
			flags->prec = va_arg(args, int);
		else if (!ft_strrchr("cspdiuxX%", *(*format)))
			flags->prec = ft_atoi(*format);
	}
	while (!ft_strrchr("cspdiuxX%", *(*format)))
		(*format)++;
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	t_flags flags;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			flags = parse_flags(&format);
			parse_other(&format, args, &flags);
			convert(&format, args, flags);
		}
		write(1, format, 1);
		format++;
	}
	va_end(args);

	printf("width %i, prec %i\n", flags.width, flags.prec);

	return (0);
}
