/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:07:34 by mfujishi          #+#    #+#             */
/*   Updated: 2021/01/14 18:01:30 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>
# include "libft/libft.h"

typedef	struct		s_format
{
	unsigned char	zerof;
	unsigned char	hyphf;
	int				widsw;
	int				width;
	int				precsw;
	int				prec;
	unsigned char	conversion;
}					t_format;

int					ft_printf(const char *s, ...);
int					ft_print(const char *s);
int					ft_format(const char *s, t_format **flag, va_list *ap);
int					ft_formatcheck(const char *s, t_format *flag, int i);
int					ft_formatprint(t_format *flags, va_list *ap, int ret);
int					print_str(char *s, t_format *flags, int freecheck);
int					print_int(int num, t_format *flags, int alllen, int numlen);
int					print_uint(unsigned int num, t_format *flags);
int					print_hex(unsigned int num, t_format *flags, char *hex);
int					print_pointer(uintptr_t point, t_format *flags);

#endif
