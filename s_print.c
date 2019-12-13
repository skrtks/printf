/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   s_print.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: skorteka <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 13:22:39 by skorteka      #+#    #+#                 */
/*   Updated: 2019/12/11 13:22:41 by skorteka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"
#include <stdarg.h>
#include <unistd.h>

/*
width > prec: width printen met daarin prec aantal char uit string
width < prec: prec aantal char printen onafhankelijk van width
width == prec: prec aantal char printen
*/

void	s_print(va_list args, t_flags flags)
{
	char *str;
	int len;
	char *width;
	str = va_arg(args, char*);
	len = ft_strlen(str);

	if (flags.width == -1 && flags.prec == -1)
		ft_putstr_fd(str, 1);
	else if (flags.prec >= flags.width)
	{
		len = (flags.prec > len ? len : flags.prec);
		write(1, str, len);
	}
	else if (flags.prec < flags.width)
	{
		if (flags.minus == 1)
		{
			len = (flags.prec > len ? len : flags.prec);
			write(1, str, len);
		}
		if (flags.width != 0)
		{
			if (flags.prec != -1)
				len = (flags.prec > len ? len : flags.prec);
			width = malloc((flags.width - len + 1) * sizeof(char));
			if (!width)
			return ;
			width[flags.width - len] = '\0';
			ft_memset(width, ' ', flags.width - len);
			ft_putstr_fd(width, 1);
			free(width);
		}
		if (flags.minus == -1)
		{
			if (flags.prec != -1)
				len = (flags.prec > len ? len : flags.prec);
			write(1, str, len);
		}
	}
}