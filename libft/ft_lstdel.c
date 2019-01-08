/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 21:05:57 by wjeyne-d          #+#    #+#             */
/*   Updated: 2018/12/12 21:10:21 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst != NULL && del != NULL)
	{
		if ((*alst)->next != NULL)
			ft_lstdel(&(*alst)->next, del);
		ft_lstdelone(alst, del);
	}
}
