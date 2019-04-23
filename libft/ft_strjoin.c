/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:58:01 by wjeyne-d          #+#    #+#             */
/*   Updated: 2018/12/08 18:57:44 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	l;
	char	*fresh;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	l = ft_strlen(s1) + ft_strlen(s2);
	fresh = (char *)malloc(sizeof(char) * (l + 1));
	i = 0;
	if (fresh == NULL)
		return (NULL);
	while (i < l && *s1 != '\0')
	{
		fresh[i] = *s1;
		i++;
		s1++;
	}
	while (i < l && *s2 != '\0')
	{
		fresh[i] = *s2;
		i++;
		s2++;
	}
	fresh[i] = '\0';
	return (fresh);
}
