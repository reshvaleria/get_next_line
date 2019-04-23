/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:55:44 by wjeyne-d          #+#    #+#             */
/*   Updated: 2018/12/08 19:07:44 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t l;
	size_t nlen;
	size_t hlen;

	if (ft_strcmp("", needle) == 0)
		return ((char *)haystack);
	nlen = ft_strlen(needle);
	hlen = ft_strlen(haystack);
	if (nlen > len || hlen < nlen)
		return (NULL);
	l = 0;
	while (l <= len - nlen)
	{
		if (ft_strncmp(haystack + l, needle, nlen) == 0)
			return ((char *)haystack + l);
		l++;
	}
	return (NULL);
}
