/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   perc_print.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: skorteka <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/23 15:08:11 by skorteka      #+#    #+#                 */
/*   Updated: 2019/12/23 15:08:12 by skorteka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"
#include <stdarg.h>
#include <unistd.h>

int	perc_print(t_flags flags)
{
	char c;
	char *width;
	int output;

	output = 0;
	c = '%';

	if (flags.minus == 1)
			write(1, &c, 1);
	if (flags.width != -1)
	{
		width = malloc((flags.width) * sizeof(char));
		// TODO: think about error checking
		if (!width)
		return (output);
		width[flags.width - 1] = '\0';
		output += flags.width - 1;
		flags.zero = (flags.zero == 1 && flags.minus == -1 ? '0' : ' ');
		ft_memset(width, flags.zero, flags.width - 1);
		ft_putstr_fd(width, 1);
		free(width);
	}
	if (flags.minus == -1)
		write(1, &c, 1);
	output++;
	return(output);
}
