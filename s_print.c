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
Als w en p -1 zijn dan s printen
als p en niet w dan checken of p langer is dan l en l of p char printen
als w en niew p dan w - l + 1 printen mits groter dan 0
als p en w dan 
*/

int	s_print(va_list args, t_flags flags)
{
	char *str;
	char *width;
	int len;
	int output;

	output = 0;
	str = va_arg(args, char*);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (flags.prec != -1)
				len = (flags.prec > len ? len : flags.prec);
	if (flags.width == -1 && flags.prec == -1)
	{
		ft_putstr_fd(str, 1);
		return (len);
	}
	else if (flags.prec > flags.width)
	{
		write(1, str, len);
		return (flags.prec > len ? len : flags.prec);
	}
	else if (flags.prec <= flags.width)
	{
		if (flags.minus == 1)
			write(1, str, len);
		output = len;
		if (flags.width != -1 && (flags.width - len + 1) > 0)
		{
			width = malloc((flags.width - len + 1) * sizeof(char));
			// TODO: think about error checking
			if (!width)
				return (output);
			width[flags.width - len] = '\0';
			ft_memset(width, ' ', flags.width - len);
			ft_putstr_fd(width, 1);
			free(width);
			output = flags.width;
		}
		if (flags.minus == -1)
			write(1, str, len);
	}
	return (output);
}