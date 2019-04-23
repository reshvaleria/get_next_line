/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:23:49 by wjeyne-d          #+#    #+#             */
/*   Updated: 2018/12/10 14:14:06 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh;
	unsigned int	ind;

	if (s == NULL)
		return (NULL);
	fresh = ft_strnew(ft_strlen(s));
	if (fresh != NULL && f != NULL)
	{
		ind = 0;
		while (s[ind] != '\0')
		{
			fresh[ind] = f(ind, s[ind]);
			ind++;
		}
	}
	return (fresh);
}
