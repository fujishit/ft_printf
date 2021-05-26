/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 13:42:33 by mfujishi          #+#    #+#             */
/*   Updated: 2020/11/12 15:20:02 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	len;

	if (s == NULL || f == NULL)
		return (0);
	if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	len = 0;
	while (s[len] != '\0')
	{
		ret[len] = f(len, s[len]);
		len++;
	}
	ret[len] = '\0';
	return (ret);
}
