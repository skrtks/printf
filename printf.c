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
	flags.plus = 0;
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

static size_t	get_index(const char *str, char c)
{
	size_t l;

	l = 0;
	while (str[l] != '\0' && str[l] != c)
		l++;
	return (l);
}

static int write_string(const char **format)
{
	int p_ind;
	int s_ind;
	char *str;

	p_ind = get_index(*format, '%');
	str = malloc((p_ind + 1) * sizeof(char));
	if (!str)
		return (0);
	s_ind = 0;
	while (*(*format) != '%' && *(*format))
	{
		str[s_ind] = *(*format);
		s_ind++;
		(*format)++;
	}
	ft_putstr_fd(str, 1);
	free(str);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	t_flags flags;

	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			// write(1, format, 1);
			// format++;
			if (!write_string(&format))
				return (0);

		}
		if (*format == '%')
		{
			format++;
			flags = parse_flags(&format);
			parse_other(&format, args, &flags);
			convert(&format, args, flags);
		}
	}
	va_end(args);
	return (0);
}
