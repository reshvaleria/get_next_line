/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:56:18 by wjeyne-d          #+#    #+#             */
/*   Updated: 2019/01/06 20:16:43 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int ft_is_next_line(**buf, **tmp)
{
	char *ptr;

	if (ptr = ft_strchr(buf, '\n'))
	{
		tmp = ft_strnew(ptr - buf);
		ft_memmove(tmp, buf, ptr - buf);
		strcpy(buf, buf + (ptr - buf));
		//line = ft_strjoin
		// ptr[0] = '\0';
		// if (tmp)
		// {
		// 	stack = ft_strjoin(tmp, ptr);
		// }
		// stack = ptr;
		// line = ft_strdup(buf);
		return(1);
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char buf[BUFF_SIZE + 1];
	int r;
	char *tmp;
	char *stack;
	//

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	while((r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[0] = '\0';
		if(ft_is_next_line(&buf, &tmp))
		{
			line = ft_strjoin(stack, tmp);
			free(tmp);
			return(1);
		}
		else
		{

		}
	//	buf[r] = '\0';




	// }
	// //	printf("%d\n %s\n", r, buf);
	// return(0);
}
