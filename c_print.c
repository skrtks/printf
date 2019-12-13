/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   c_print.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: skorteka <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 12:04:32 by skorteka      #+#    #+#                 */
/*   Updated: 2019/12/11 12:04:34 by skorteka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"
#include <stdarg.h>
#include <unistd.h>

void	c_print(va_list args, t_flags flags)
{
	char c;
	char *width;
	c = va_arg(args, int);

	if (flags.minus == 1)
			write(1, &c, 1);
	if (flags.width != -1)
	{
		width = malloc((flags.width) * sizeof(char));
		if (!width)
		return ;
		width[flags.width - 1] = '\0';
		ft_memset(width, ' ', flags.width - 1);
		ft_putstr_fd(width, 1);
		free(width);
	}
	if (flags.minus == -1)
		write(1, &c, 1);
}
