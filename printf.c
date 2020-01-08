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

#include "./libft/libft.h"
#include "printf.h"
#include <stdarg.h>
#include <unistd.h>

static int		convert(const char **format, va_list args, t_flags flags)
{
	int output;

	if (*(*format) == 'c' || *(*format) == '%')
		output = c_print(args, flags);
	if (*(*format) == 's')
		output = s_print(args, flags);
	if (*(*format) == 'i' || *(*format) == 'd')
		output = i_print(args, flags);
	if (*(*format) == 'u')
		output = u_print(args, flags);
	if (*(*format) == 'X' || *(*format) == 'x')
		output = x_print(args, flags);
	if (*(*format) == 'p')
		output = p_print(args, flags);
	(*format)++;
	return (output);
}

static t_flags	parse_flags(const char **format)
{
	t_flags flags;

	flags = init_flags();
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

static void		parse_other(const char **format, va_list args, t_flags *flags)
{
	if (*(*format) == '*')
		flags->width = va_arg(args, int);
	else if (!ft_strrchr("cspdiuxX%.", *(*format)))
		flags->width = ft_atoi(*format);
	while (!ft_strrchr("cspdiuxXlh%.", *(*format)))
		(*format)++;
	if (*(*format) == '.')
	{
		(*format)++;
		if (*(*format) == '*')
			flags->prec = va_arg(args, int);
		else if (ft_strrchr("cspdiuxX%", *(*format)))
			flags->prec = 0;
		else if (!ft_strrchr("cspdiuxX%", *(*format)))
			flags->prec = ft_atoi(*format);
	}
	while (!ft_strrchr("cspdiuxXlh%", *(*format)))
		(*format)++;
}

static int		write_string(const char **format)
{
	int		p_ind;
	int		s_ind;
	char	*str;

	p_ind = get_index(*format, '%');
	str = malloc((p_ind + 1) * sizeof(char));
	if (!str)
		return (0);
	str[p_ind] = '\0';
	s_ind = 0;
	while (*(*format) != '%' && *(*format))
	{
		str[s_ind] = *(*format);
		s_ind++;
		(*format)++;
	}
	ft_putstr_fd(str, 1);
	free(str);
	return (s_ind);
}

int				ft_printf(const char *format, ...)
{
	va_list	args;
	t_flags	flags;
	int		output;

	output = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			output += write_string(&format);
		}
		if (*format == '%')
		{
			format++;
			flags = parse_flags(&format);
			parse_other(&format, args, &flags);
			flags = parse_l_mod(&format, flags);
			flags.conv = *format;
			output += convert(&format, args, flags);
		}
	}
	va_end(args);
	return (output);
}
