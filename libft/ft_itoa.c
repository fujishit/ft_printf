/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:03:15 by mfujishi          #+#    #+#             */
/*   Updated: 2020/12/19 21:34:51 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit(int n, int *neg)
{
	size_t	digit;

	digit = 0;
	if (0 <= n)
	{
		*neg = 0;
		while ((n /= 10) > 0)
			digit++;
	}
	else
	{
		*neg = 1;
		digit++;
		while ((n /= 10) < 0)
			digit++;
	}
	return (digit + 1);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		neg;
	int		digit;

	neg = 0;
	digit = ft_digit(n, &neg);
	if (!(ret = (char *)malloc(sizeof(char) * (digit + 1))))
		return (0);
	ret[digit] = '\0';
	if (neg == 0)
		n *= -1;
	if (neg == 1)
		ret[0] = '-';
	while (n < -9 && digit--)
	{
		ret[digit] = ((n % 10) * -1) + '0';
		n /= 10;
	}
	ret[--digit] = ((n % 10) * -1) + '0';
	return (ret);
}
