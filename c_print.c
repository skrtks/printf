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

void	c_print(va_list args, t_flags flags)
{
	char c;
	c = va_arg(args, int);

	if (flags.minus == 0)

	ft_putchar_fd(c, 1);
}
