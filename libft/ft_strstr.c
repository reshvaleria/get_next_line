/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:56:13 by wjeyne-d          #+#    #+#             */
/*   Updated: 2018/12/08 18:47:52 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t l;

	if (ft_strcmp("", needle) == 0)
		return ((char *)haystack);
	i = 0;
	l = ft_strlen(needle);
	while (haystack[i] != '\0')
	{
		if (ft_strncmp(haystack + i, needle, l) == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
