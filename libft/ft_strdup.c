/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 21:18:32 by wjeyne-d          #+#    #+#             */
/*   Updated: 2018/12/10 14:13:32 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		l;
	char	*new;

	l = 0;
	while (s1[l] != '\0')
		l++;
	if (!(new = (char*)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	i = 0;
	while (i <= l)
	{
		new[i] = s1[i];
		i++;
	}
	return (new);
}
