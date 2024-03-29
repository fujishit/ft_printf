/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:05:50 by mfujishi          #+#    #+#             */
/*   Updated: 2020/11/05 15:36:23 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	int				ret;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ret = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (n-- && (ret = ss1[i] - ss2[i]) == 0 && ss1[i] != '\0')
		i++;
	return (ret);
}
