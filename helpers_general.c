/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers_general.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: skorteka <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 12:32:29 by skorteka      #+#    #+#                 */
/*   Updated: 2020/01/07 12:32:30 by skorteka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "printf.h"
#include <stdarg.h>

t_flags	init_flags(void)
{
	t_flags flags;

	flags.minus = -1;
	flags.zero = -1;
	flags.hash = -1;
	flags.apo = -1;
	flags.space = -1;
	flags.plus = -1;
	flags.width = -1;
	flags.prec = -1;
	flags.conv = 'q';
	return (flags);
}