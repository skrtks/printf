/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: skorteka <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 09:30:56 by skorteka      #+#    #+#                 */
/*   Updated: 2019/12/11 09:31:00 by skorteka      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_flags
{
	int minus;
	int zero;
	int hash;
	int apo;
	int space;
	int plus;
	int width;
	int prec;
} 				t_flags;

int ft_printf(const char *format, ...);
int	c_print(va_list args, t_flags flags);
int	s_print(va_list args, t_flags flags);
int	i_print(va_list args, t_flags flags);

# endif
