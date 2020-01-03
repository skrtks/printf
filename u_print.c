/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   u_print.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: skorteka <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/23 09:27:05 by skorteka      #+#    #+#                 */
/*   Updated: 2019/12/23 09:27:07 by skorteka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"
#include <stdarg.h>
#include <unistd.h>

static t_length	get_length(t_flags flags, unsigned int num)
{
	t_length len;

	len.numlen = ((flags.prec == 0 && num == 0) ? 0 : int_length(num));
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

static void		fill_width(t_flags flags, t_length len, int *i, char **str)
{
	*i = 0;
	if (flags.minus == -1)
	{
		ft_memset(((*str) + *i), flags.zero, len.w_padlen);
		(*i) += len.w_padlen;
	}
	if (flags.minus == 1)
		ft_memset(((*str) + len.t_numlen), flags.zero, len.w_padlen);
}

static char		*create_string(t_flags flags, t_length len, unsigned int num)
{
	char	*str;
	char	*num_str;
	int		i;
	int		j;

	str = malloc((len.total_len + 1) * sizeof(char));
	num_str = ft_itoa_uns(num);
	if (!str || !num_str)
		return (NULL);
	flags.zero = ((flags.prec == -1 && flags.zero == 1) ? '0' : ' ');
	fill_width(flags, len, &i, &str);
	ft_memset((str + i), '0', len.p_padlen);
	i += len.p_padlen;
	j = 0;
	while (num_str[j] && flags.prec != 0)
	{
		str[i] = num_str[j];
		i++;
		j++;
	}
	free(num_str);
	if (flags.minus == 1)
		i += len.w_padlen;
	str[i] = '\0';
	return (str);
}

int				u_print(va_list args, t_flags flags)
{
	unsigned int	num;
	t_length		len;
	int				slen;
	char			*str;

	num = (unsigned int)va_arg(args, int);
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
