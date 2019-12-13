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

void s_print(const char *format, t_flags flags)
{
	char *str;
	char *width;
	str = va_arg(args, int);


	if (flags.width <= flags.prec)

	if (flags.minus == 1)
			ft_putstr_fd(str, 1);
	if (flags.width != 0)
	{
		width = malloc((flags.width) * sizeof(char));
		if (!width)
		return ;
		width[flags.width - 1] = '\0';
		ft_memset(width, ' ', flags.width - 1);
		ft_putstr_fd(width, 1);
		free(width);
	}
	if (flags.minus == 0)
		ft_putstr_fd(str, 1);
}