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

static t_length	get_length(t_flags flags, long num)
{
	t_length len;

	len.sign = (num < 0 ? '-' : '+');
	len.sign = ((flags.space == 1 && flags.plus == -1 && num >= 0)
				? ' ' : len.sign);
	len.numlen = ((flags.prec == 0 && num == 0) ? 0 : int_length(num));
	len.numlen += (flags.apo == 1 ? sep_calculator(num) : 0);
	len.p_padlen = ((flags.prec != -1 && flags.prec >= len.numlen) ?
					flags.prec - len.numlen : 0);
	len.p_numlen = len.numlen + len.p_padlen;
	len.t_numlen = ((len.sign == '-' || (len.sign == '+' && flags.plus == 1)
					|| flags.space == 1) ? len.p_numlen + 1 : len.p_numlen);
	len.w_padlen = ((flags.width != -1 && flags.width >= len.t_numlen) ?
					flags.width - len.t_numlen : 0);
	len.total_len = len.t_numlen + len.w_padlen;
	return (len);
}

static void		fill_width(t_flags flags, t_length len, t_index *index, char **str)
{
	index->i = 0;
	if ((len.sign == '-' || flags.plus == 1 || flags.space == 1)
		&& flags.zero == '0' && flags.minus == -1)
	{
		(*str)[index->i] = len.sign;
		(index->i)++;
	}
	if (flags.minus == -1)
	{
		ft_memset(((*str) + index->i), flags.zero, len.w_padlen);
		(index->i) += len.w_padlen;
	}
	if ((len.sign == '-' || flags.plus == 1 || flags.space == 1)
		&& (flags.zero == ' '))
	{
		(*str)[index->i] = len.sign;
		(index->i)++;
	}
	if (flags.minus == 1)
		ft_memset(((*str) + len.t_numlen), flags.zero, len.w_padlen);
}

static char		*create_string(t_flags flags, t_length len, long num)
{
	char	*str;
	char	*num_str;
	t_index	index;

	str = ft_calloc((len.total_len + 1), sizeof(char));
	num_str = ft_itoa_base((int)num, 10);
	if (!str || !num_str)
		return (NULL);
	flags.zero = ((flags.prec == -1 && flags.zero == 1) ? '0' : ' ');
	fill_width(flags, len, &index, &str);
	ft_memset((str + index.i), '0', len.p_padlen);
	index.i += len.p_padlen;
	index.j = ((len.sign == '-') ? 1 : 0);
	if (flags.apo == 1)
		str = set_separators(num, len, str, index.i);
	// set_num(flags, str, num_str, &i);
	while (num_str[index.j] && flags.prec != 0)
	{
		if (str[index.i] == '\0')
		{
			str[index.i] = num_str[index.j];
			index.j++;
		}
		index.i++;
	}
	free(num_str);
	if (flags.minus == 1)
		index.i += len.w_padlen;
	str[index.i] = '\0';
	return (str);
}

int				i_print(va_list args, t_flags flags)
{
	long		num;
	t_length	len;
	int			slen;
	char		*str;

	num = (long)va_arg(args, int);
	flags.apo = (flags.apo == 1 ? 1 : 0);
	len = get_length(flags, num);
	str = create_string(flags, len, num);
	if (!str)
		return (0);
	slen = ft_strlen(str);
	write(1, str, slen);
	if (str)
		free(str);
	return (slen);
}
