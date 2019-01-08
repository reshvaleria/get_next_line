/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 21:06:34 by wjeyne-d          #+#    #+#             */
/*   Updated: 2018/12/12 21:04:17 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	*res;

	if (!lst || !f)
		return (NULL);
	newlist = f(lst);
	res = newlist;
	lst = lst->next;
	while (lst)
	{
		if (!(newlist->next = f(lst)))
		{
			while (res->next)
			{
				newlist = res->next;
				free(res);
				res = newlist;
			}
		}
		lst = lst->next;
		newlist = newlist->next;
	}
	return (res);
}
