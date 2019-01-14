/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:56:18 by wjeyne-d          #+#    #+#             */
/*   Updated: 2019/01/09 20:55:11 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int ft_is_next_line(char **buf, char **tmp)
{
	char *ptr;
	int len;

ptr = ft_strchr((char *)buf, '\n');
	if (ptr)
	{
		len = ptr - (char *)buf + 1;
		*tmp = ft_strnew(len);
		ft_strncpy(*tmp, (char *)buf, (len - 1));
		printf("tmp: %s\n", *tmp);

		ft_strcpy((char *)buf, ((char *)buf + len));

		//дальше лажа
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
	 char buf[BUFF_SIZE + 1];
	int r;
	char *tmp;
	char *stack;
	//

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	while((r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		printf("read bytes: %d\n", r);
		printf("buf is: %s\n", buf);

		buf[0] = '\0';
		stack = *line;
		printf("stack: %s\n", stack);
		printf("line: %s\n", *line);



		if(ft_is_next_line((char **)&buf, &tmp))
		{
			line = (char **)ft_strjoin(stack, tmp);
			printf("%s\n", *line);

			free(tmp);
			return(1);
		}
		else
		{
			line = (char **)ft_strjoin(stack, buf);
		}
	}
		return(0);
	//	buf[r] = '\0';




	// }
	// //	printf("%d\n %s\n", r, buf);
	// return(0);
}
