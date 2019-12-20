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
	char zero;
	int hash;
	int apo;
	int space;
	int plus;
	int width;
	int prec;
} 				t_flags;

typedef struct s_length {
	int numlen;
	int p_numlen;
	int t_numlen;
	int p_padlen;
	int w_padlen;
	int total_len;
	char sign;
}		t_length;

int ft_printf(const char *format, ...);
int	c_print(va_list args, t_flags flags);
int	s_print(va_list args, t_flags flags);
int	i_print(va_list args, t_flags flags);

# endif
