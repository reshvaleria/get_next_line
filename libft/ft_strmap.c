/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:55:21 by wjeyne-d          #+#    #+#             */
/*   Updated: 2018/12/12 23:10:50 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	size_t	i;

	if (s == NULL)
		return (NULL);
	fresh = ft_strnew(ft_strlen(s));
	if (fresh != NULL && f != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			fresh[i] = f(s[i]);
			i++;
		}
	}
	return (fresh);
}
