/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_print.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: skorteka <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/23 14:18:27 by skorteka      #+#    #+#                 */
/*   Updated: 2019/12/23 14:18:29 by skorteka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"
#include <stdarg.h>
#include <unistd.h>

static t_length	get_length(t_flags flags, unsigned long long num)
{
	t_length	len;
	char		*str;

	str = ft_itoa_base(num, 16);
	len.t_numlen = ft_strlen(str);
	len.w_padlen = (flags.width - len.t_numlen - 2 < 0 ? 0 :
					flags.width - len.t_numlen - 2);
	len.total_len = len.w_padlen + len.t_numlen + 2;
	return (len);
}

static void		fill_width(t_flags flags, t_length len, int *i, char **str)
{
	int extra_for_hash;

	*i = 0;
	if (flags.minus == -1)
	{
		ft_memset(((*str) + *i), flags.zero, len.w_padlen);
		(*i) += len.w_padlen;
	}
	if (flags.minus == 1)
	{
		extra_for_hash = 2;
		ft_memset(((*str) + extra_for_hash + len.t_numlen),
					flags.zero, len.w_padlen);
	}
}

static char		*create_string(t_flags flags, t_length len,
								unsigned long long num)
{
	char	*str;
	char	*num_str;
	int		i;
	int		j;

	str = malloc((len.total_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	num_str = ft_itoa_base(num, 16);
	flags.zero = ' ';
	fill_width(flags, len, &i, &str);
	if (flags.zero == ' ')
		i = set_string(&str, "0x", i);
	j = 0;
	if (flags.prec != 0)
		i = set_string(&str, num_str, i);
	if (flags.minus == 1)
		i += len.w_padlen;
	str[i] = '\0';
	return (str);
}

int				p_print(va_list args, t_flags flags)
{
	unsigned long long	num;
	t_length			len;
	char				*str;

	num = (unsigned long long)va_arg(args, void*);
	len = get_length(flags, num);
	str = create_string(flags, len, num);
	if (!str)
		return (0);
	write(1, str, ft_strlen(str));
	if (str)
		free(str);
	return (ft_strlen(str));
}
