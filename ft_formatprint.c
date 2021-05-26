/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 23:10:23 by mfujishi          #+#    #+#             */
/*   Updated: 2021/01/14 17:52:02 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *s, t_format *flags, int freecheck)
{
	int		i;
	char	*sstr;
	int		sstrlen;
	int		slen;

	s = (!s) ? "(null)" : s;
	if (flags->conversion == 's' && flags->zerof == '0' && flags->hyphf == '-')
		flags->zerof = 0;
	slen = flags->conversion == 'c' ? 1 : ft_strlen(s);
	if (!(flags->prec < 0 || slen < flags->prec || flags->precsw == -1))
		slen = flags->prec;
	i = 0;
	sstrlen = slen < flags->width ? flags->width - slen : 0;
	if (!(sstr = (char *)malloc(sizeof(char) * sstrlen + 1)))
		return (-1);
	while (i < sstrlen)
		sstr[i++] = flags->zerof == '0' ? '0' : ' ';
	write(1, sstr, flags->hyphf == '-' || flags->hyphf == '-' ? 0 : i);
	write(1, s, slen);
	write(1, sstr, flags->hyphf == '-' || flags->hyphf == '-' ? i : 0);
	free(sstr);
	if (freecheck == 1)
		free(s);
	return (slen + i);
}

int	print_int(int num, t_format *flags, int alllen, int numlen)
{
	char	*s;
	char	*ps;
	int		zerolen;

	if ((s = ft_itoa(num)) == NULL)
		return (-1);
	flags->zerof = flags->hyphf != 0 || flags->precsw != -1 ? 0 : flags->zerof;
	numlen = ft_strlen(s);
	alllen = flags->precsw == -1 || flags->prec < numlen ? numlen : flags->prec;
	alllen = num < 0 && numlen < flags->prec ? alllen + 1 : alllen;
	alllen = flags->zerof == '0' && flags->widsw != -1 && flags->precsw == -1
	&& numlen < flags->width ? flags->width : alllen;
	alllen = num < 0 && flags->prec == numlen ? alllen + 1 : alllen;
	if ((ps = (char *)malloc(sizeof(char) * (alllen + 1))) == NULL)
		return (-1);
	zerolen = num < 0 ? (alllen + 1) - numlen : alllen - numlen;
	ps[0] = num < 0 ? '-' : '\0';
	if (!(num == 0 && flags->precsw != -1 && flags->prec == 0))
		ft_strlcpy(ps + zerolen, num < 0 ? s + 1 : s, (numlen + 1));
	flags->prec = alllen;
	alllen = num < 0 ? 1 : 0;
	while (alllen < zerolen)
		ps[alllen++] = '0';
	free(s);
	return (print_str(ps, flags, 1));
}

int	print_uint(unsigned int num, t_format *flags)
{
	char			*ps;
	unsigned int	digitnum;
	int				len;
	int				zerolen;

	flags->zerof = flags->precsw != -1 ? 0 : flags->zerof;
	if (num == 0 && flags->precsw != -1 && flags->prec == 0)
		return (print_str("\0", flags, 0));
	len = 1;
	digitnum = num;
	while ((digitnum /= 10) != 0)
		len++;
	flags->prec = flags->precsw == -1 || flags->prec < len ? len : flags->prec;
	if ((ps = malloc(sizeof(char) * (flags->prec + 1))) == NULL)
		return (-1);
	ps[flags->prec] = '\0';
	zerolen = flags->prec - len;
	while (len-- != 0)
	{
		ps[len + zerolen] = (num % 10) + '0';
		num /= 10;
	}
	while (zerolen-- != 0)
		ps[zerolen] = '0';
	return (print_str(ps, flags, 1));
}

int	print_hex(unsigned int num, t_format *flags, char *hex)
{
	unsigned int	digitnum;
	int				len;
	char			*s;
	int				zerolen;

	flags->zerof = flags->precsw != -1 ? 0 : flags->zerof;
	if (num == 0 && flags->precsw != -1 && flags->prec == 0)
		return (print_str("\0", flags, 0));
	len = 1;
	digitnum = num;
	while ((digitnum /= 16) > 0)
		len++;
	flags->prec = flags->precsw == -1 || flags->prec < len ? len : flags->prec;
	if ((s = (char *)malloc(sizeof(char) * (flags->prec + 1))) == NULL)
		return (-1);
	s[flags->prec] = '\0';
	zerolen = flags->prec - len;
	while (len-- > 0)
	{
		s[zerolen + len] = hex[num % 16];
		num /= 16;
	}
	while (zerolen-- != 0)
		s[zerolen] = '0';
	return (print_str(s, flags, 1));
}

int	print_pointer(uintptr_t point, t_format *flags)
{
	uintptr_t	digitnum;
	char		*hex;
	int			len;
	char		*s;

	len = point == 0 && flags->precsw != -1 && flags->prec == 0 ? 2 : 3;
	digitnum = point;
	while ((digitnum /= 16) > 0)
		len++;
	hex = "0123456789abcdefg";
	len = len < flags->prec && flags->precsw != -1 ? flags->prec + 2 : len;
	flags->prec = len;
	if ((s = malloc(sizeof(char) * len + 1)) == NULL)
		return (-1);
	s[len] = '\0';
	s[0] = '0';
	s[1] = 'x';
	while (len-- > 2)
	{
		s[len] = hex[point % 16];
		point /= 16;
	}
	return (print_str(s, flags, 1));
}
