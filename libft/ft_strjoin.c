/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:35:56 by mfujishi          #+#    #+#             */
/*   Updated: 2020/11/14 13:44:44 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!(ret = (char *)malloc((sizeof(char) * len))))
		return (0);
	len = 0;
	while (*s1 != '\0')
		ret[len++] = *s1++;
	while (*s2 != '\0')
		ret[len++] = *s2++;
	ret[len] = '\0';
	return (ret);
}
