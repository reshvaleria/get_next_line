/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:47:42 by wjeyne-d          #+#    #+#             */
/*   Updated: 2018/12/12 22:03:20 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			l;
	unsigned char	*str1;
	unsigned char	*str2;
	int				res;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	l = 0;
	if (n == 0)
		return (0);
	while (l < n)
	{
		res = (str1[l] - str2[l]);
		l++;
		if (res != 0)
			return (res);
	}
	return (res);
}
