/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:58:26 by wjeyne-d          #+#    #+#             */
/*   Updated: 2018/12/08 19:08:52 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	size_t	i;
	int		word;

	word = 0;
	i = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			while (s[i] != c)
				i++;
			word++;
		}
		if (s[i] == c)
			i++;
	}
	return (word);
}

static int	ft_letter_count(char const *s, int si, char c)
{
	int l;

	l = 0;
	while (s[si] != c)
	{
		l++;
		si++;
	}
	return (l);
}

static void	ft_free_all(char **new, int wi)
{
	int i;

	i = 0;
	while (i < wi)
	{
		ft_strdel(&new[i]);
		i++;
	}
	free(new);
	new = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	int		words;
	int		wi;
	int		si;
	char	**new;

	if (s == NULL)
		return (NULL);
	words = ft_count(s, c);
	if (!(new = (char**)ft_memalloc(sizeof(char*) * (words + 1))))
		return (NULL);
	si = 0;
	wi = 0;
	while (wi < words)
	{
		while (s[si] == c)
			si++;
		if (!(new[wi] = ft_strsub(s, si, ft_letter_count(s, si, c))))
		{
			ft_free_all(new, wi);
			return (NULL);
		}
		si = si + ft_letter_count(s, si, c);
		wi++;
	}
	return (new);
}
