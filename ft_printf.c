/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 12:35:17 by mfujishi          #+#    #+#             */
/*   Updated: 2021/01/14 03:12:48 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list		ap;
	t_format	*flags;
	int			ret;
	int			tmp;

	va_start(ap, s);
	ret = 0;
	while (*s != '\0')
		if (*s == '%')
		{
			if ((tmp = ft_format(s, &flags, &ap)) == -1)
				return (-1);
			s += tmp;
			if ((tmp = ft_formatprint(flags, &ap, 0)) == -1)
				return (-1);
			ret += tmp;
		}
		else
		{
			tmp = ft_print(s);
			ret += tmp;
			s += tmp;
		}
	return (ret);
}

int	ft_print(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '%' && s[len] != '\0')
		len++;
	write(1, s, len);
	return (len);
}

int	ft_format(const char *s, t_format **flag, va_list *ap)
{
	t_format	*flags;
	int			len;

	if ((flags = (t_format *)malloc(sizeof(t_format))) == NULL)
		return (-1);
	flags->conversion = 0;
	len = ft_formatcheck(s, flags, 1);
	flags->width = flags->widsw == '*' ? va_arg(*ap, int) : flags->width;
	flags->prec = flags->precsw == '*' ? va_arg(*ap, int) : flags->prec;
	if (flags->width <= (INT_MIN + 1) || INT_MAX <= flags->width)
	{
		free(flags);
		return (-1);
	}
	if (flags->width < 0)
	{
		flags->hyphf = '-';
		flags->zerof = 0;
		flags->width = flags->width * -1;
	}
	if (flags->prec < 0)
		flags->precsw = -1;
	*flag = flags;
	return (len);
}

int	ft_formatcheck(const char *s, t_format *flags, int i)
{
	flags->zerof = 0;
	flags->hyphf = 0;
	flags->width = 0;
	flags->prec = 0;
	while (s[i] == '0' || s[i] == '-')
	{
		flags->zerof = s[i] == '0' ? s[i++] : flags->zerof;
		flags->hyphf = s[i] == '-' ? s[i++] : flags->hyphf;
	}
	flags->widsw = s[i] == '*' || s[i] == '-' || ft_isdigit(s[i]) ? s[i] : -1;
	flags->width = ft_atoi(s + i);
	s[i] == '*' || s[i] == '-' ? i++ : i;
	while ('0' <= s[i] && s[i] <= '9' && s[i] != '\0')
		i++;
	flags->precsw = s[i] == '.' ? ++i : -1;
	flags->precsw = flags->precsw == i || (s[i] == '*' || s[i] == '-' ||
	ft_isdigit(s[i])) ? s[i] : -1;
	flags->prec = ft_atoi(s + i);
	s[i] == '*' || s[i] == '-' ? i++ : i;
	while ('0' <= s[i] && s[i] <= '9' && s[i] != '\0')
		i++;
	if (s[i] == 'c' || s[i] == 's' || s[i] == 'p' || s[i] == 'd' || s[i] == 'i'
	|| s[i] == 'u' || s[i] == 'x' || s[i] == 'X' || s[i] == '%')
		flags->conversion = s[i++];
	return (i);
}

int	ft_formatprint(t_format *flags, va_list *ap, int ret)
{
	char	pchar[2];

	if (flags->conversion == 'c' || flags->conversion == '%')
	{
		flags->zerof = flags->hyphf != '-' && flags->zerof == '0' ? '0' : 0;
		flags->prec = 1;
		pchar[0] = flags->conversion == '%' ? '%' : va_arg(*ap, int);
		pchar[1] = '\0';
		ret = print_str(pchar, flags, 0);
	}
	else if (flags->conversion == 's')
		ret = print_str(va_arg(*ap, char *), flags, 0);
	else if (flags->conversion == 'p')
		ret = print_pointer((uintptr_t)va_arg(*ap, void *), flags);
	else if (flags->conversion == 'd' || flags->conversion == 'i')
		ret = print_int(va_arg(*ap, int), flags, 0, 0);
	else if (flags->conversion == 'u')
		ret = print_uint(va_arg(*ap, unsigned int), flags);
	else if (flags->conversion == 'x')
		ret = print_hex(va_arg(*ap, int), flags, "0123456789abcdef");
	else if (flags->conversion == 'X')
		ret = print_hex(va_arg(*ap, int), flags, "0123456789ABCDEF");
	free(flags);
	return (ret);
}
