/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:21:21 by mfujishi          #+#    #+#             */
/*   Updated: 2020/11/06 14:58:48 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (s == NULL)
		return (0);
	if (ft_strlen(s) < start || len <= 0)
	{
		if (!(ret = (char *)malloc(1)))
			return (0);
		ret[0] = '\0';
		return (ret);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	if (!(ret = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (i < len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
