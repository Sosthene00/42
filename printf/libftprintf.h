/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaubert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 14:33:56 by agaubert          #+#    #+#             */
/*   Updated: 2020/01/31 17:49:57 by agaubert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <strings.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# include "libft/libft.h"
# define CONVERSION "ncCspPdDiIuUxX%"
# define FLAGS "-0.*+#hl"
# define INVALID_PARAMS "There's something wrong with your argument\n"
# define NULL_POINTER "pointer is null and/or c == 0\n"

typedef	struct		s_param
{
	char			type;
	size_t			padding;
	size_t			zero;
	int				precision;
	int				width;
	size_t			is_valid;
	int				len;
	size_t			sign;
	size_t			alt;
	int				len_modif;
}					t_param;

int					ft_printf(const char *format, ...);

int					format_int(int x, t_param *params);

int					format_long(long x, t_param *params);

int					format_longlong(long long x, t_param *params);

int					format_ulonglong(unsigned long long x, t_param *params);

int					format_uint(unsigned int x, t_param *params);

int					format_ulong(unsigned long x, t_param *params);

int					format_xint(unsigned int x, t_param *params);

int					format_xlong(unsigned long x, t_param *params);

int					format_xlonglong(unsigned long long x, t_param *params);

int					format_string(char *x, t_param *params);

int					format_char(char c, t_param *params);

int					format_ptr(void *ptr, t_param *params);

int					print_sign(long long x, int sign);

int					print_int(int spaces, char *zero_prec, \
					t_param *params, int x);

int					print_long(int spaces, char *zero_prec, \
					t_param *params, long x);

int					print_longlong(int spaces, char *zero_prec, \
					t_param *params, long long x);

int					print_uint(int spaces, char *zero_prec, \
					t_param *params, unsigned int x);

int					print_ulong(int spaces, char *zero_prec, \
					t_param *params, unsigned long x);
int					print_ulonglong(int spaces, char *zero_prec, \
					t_param *params, unsigned long long x);

int					print_xint(int spaces, char *zero_prec, \
					t_param *params, unsigned int x);

int					print_xlong(int spaces, char *zero_prec, \
					t_param *params, unsigned long x);

int					print_xlonglong(int spaces, char *zero_prec, \
					t_param *params, unsigned long long x);

int					parser(char *fmt, va_list ap);

t_param				*ft_newparam(char *params, va_list ap);

void				free_params(t_param **ptr);

char				*fill_uzero(unsigned int x, int pos, t_param *params);

char				*lfill_uzero(unsigned long x, int pos, t_param *params);

char				*llfill_uzero(unsigned long long x, int pos, \
					t_param *params);

int					count_digit(int n);

int					count_ldigit(long n);

int					count_lldigit(long long n);

int					count_digit_minus(int n);

int					count_ldigit_minus(long n);

int					count_lldigit_minus(long long n);

int					count_udigit(unsigned int n, int pos);

int					count_uldigit(unsigned long n, long pos);

int					count_ulldigit(unsigned long long n, long long pos);

int					count_width(char *str);

char				*create_padding(int len, int zero);

char				*fill_zero(int x, t_param *params);

char				*lfill_zero(long x, t_param *params);

char				*llfill_zero(long long x, t_param *params);

int					fill_spaces(int len);

void				print_error(int output);

int					extract_num(char *str);

size_t				convert_neg(int n);

size_t				convert_lneg(long n);

size_t				convert_llneg(long long n);

char				handle_type(char type);

int					h_modifier(t_param *node, char *str);

int					l_modifier(t_param *node, char *str);

#endif
