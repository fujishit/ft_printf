/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:24:16 by mfujishi          #+#    #+#             */
/*   Updated: 2020/11/04 16:24:17 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	if (!(ret = (char *)malloc((len * sizeof(char)) + 1)))
		return (0);
	ret[len] = '\0';
	while (len--)
		ret[len] = s[len];
	return (ret);
}
