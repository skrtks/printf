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
	int			minus;
	int			zero;
	int			hash;
	int			apo;
	int			space;
	int			plus;
	int			width;
	int			prec;
	char		conv;
}				t_flags;

typedef struct	s_length {
	int			numlen;
	int			p_numlen;
	int			t_numlen;
	int			p_padlen;
	int			w_padlen;
	int			total_len;
	char		sign;
}				t_length;

int				ft_printf(const char *format, ...);
int				c_print(va_list args, t_flags flags);
int				s_print(va_list args, t_flags flags);
int				i_print(va_list args, t_flags flags);
int				x_print(va_list args, t_flags flags);
int				p_print(va_list args, t_flags flags);

int				int_length(long n);
char			*ft_itoa_base(long long value, int base);
char			*ft_itoa_uns(int n);
int				u_print(va_list args, t_flags flags);
char			*set_case(char *str, t_flags flags);
int				set_string(char **dst, char *src, int i);
t_flags			init_flags(void);
size_t			get_index(const char *str, char c);
int				sep_calculator(int num);
char			*set_separators(long num, t_length len, char *str, int start);

#endif
