/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:56:18 by wjeyne-d          #+#    #+#             */
/*   Updated: 2019/01/09 20:34:28 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int ft_is_next_line(**buf, **tmp)
{
	char *ptr;
	int len;

	if (ptr = ft_strchr(buf, '\n'))
	{
		len = ptr - buf + 1;
		tmp = ft_strnew(len);
		ft_strncpy(tmp, buf, len - 1);
		ft_strcpy(buf, buf + len);
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
		stack = line;
		if(ft_is_next_line(&buf, &tmp))
		{
			line = ft_strjoin(stack, tmp);
			free(tmp);
			return(1);
		}
		else
		{
			line = ft_strjoin(stack, buf);
		}
		return(0);
	//	buf[r] = '\0';




	// }
	// //	printf("%d\n %s\n", r, buf);
	// return(0);
}
