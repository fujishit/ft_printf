/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 00:37:42 by mfujishi          #+#    #+#             */
/*   Updated: 2020/11/08 00:37:43 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newlist;

	if (!(newlist = (t_list *)malloc(sizeof(t_list))))
		return (0);
	newlist->content = content;
	newlist->next = NULL;
	return (newlist);
}
