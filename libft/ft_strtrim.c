/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:58:15 by wjeyne-d          #+#    #+#             */
/*   Updated: 2018/12/08 18:46:42 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	size_t			l;
	char			*fresh;

	if (s == NULL)
		return (NULL);
	i = 0;
	l = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
	{
		fresh = ft_strnew(0);
		return (fresh);
	}
	while (s[l] == ' ' || s[l] == '\n' || s[l] == '\t')
		l--;
	l = l - (size_t)i + 1;
	fresh = ft_strsub(s, i, l);
	return (fresh);
}
