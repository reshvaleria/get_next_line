/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 23:35:01 by wjeyne-d          #+#    #+#             */
/*   Updated: 2018/12/08 19:40:11 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	size;

	size = 0;
	i = 0;
	while (s1[size] != '\0' && s2[size] != '\0'
	&& s1[size] == s2[size] && size < n - 1)
		size++;
	if (s1[size] != s2[size] && size < n)
		i = (unsigned char)s1[size] - (unsigned char)s2[size];
	return (i);
}
