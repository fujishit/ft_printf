/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:47:16 by mfujishi          #+#    #+#             */
/*   Updated: 2020/11/11 15:00:46 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*retlst;
	t_list	*nextlst;
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return (0);
	if ((retlst = ft_lstnew(f(lst->content))) == NULL)
		return (0);
	tmp = retlst;
	lst = lst->next;
	while (lst != NULL)
	{
		if ((nextlst = ft_lstnew(f(lst->content))) == NULL)
		{
			ft_lstclear(&retlst, del);
			return (0);
		}
		tmp->next = nextlst;
		tmp = nextlst;
		lst = lst->next;
	}
	return (retlst);
}
