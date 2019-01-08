/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 22:29:21 by wjeyne-d          #+#    #+#             */
/*   Updated: 2018/12/12 22:47:02 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int				plusmin;
	unsigned long	res;

	res = 0;
	plusmin = 1;
	while ((*s == 32) || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-')
	{
		plusmin = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + *s - '0';
		if (res >= 9223372036854775807 && plusmin == 1)
			return (-1);
		if (res > 9223372036854775807 && plusmin == -1)
			return (0);
		s++;
	}
	return (res * plusmin);
}
