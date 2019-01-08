/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:46:35 by wjeyne-d          #+#    #+#             */
/*   Updated: 2018/12/08 18:44:12 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			l;
	unsigned char	*d;
	unsigned char	*s;

	l = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (l < n)
	{
		d[l] = s[l];
		if (d[l] == (unsigned char)c)
			return (d + ++l);
		l++;
	}
	return (NULL);
}
