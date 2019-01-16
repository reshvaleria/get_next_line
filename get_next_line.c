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

static int ft_is_next_line(char **stack, char **line)
{
	char *ptr;
	char *tmp;
//	int len;

	ptr = ft_strchr(*stack, '\n');
	printf("PTR ISNEXTLINE: %s\n", ptr);

	if (ptr)
	{
	//	len = ptr - *stack + 1;
	tmp = &*ptr;
	*tmp = '\0';
	*line = ft_strdup(*stack);
	*stack = ft_strdup(tmp + 1);
	return (1);
	//	*tmp = ft_strnew(len);
	//	ft_strncpy(*tmp, *stack, (len - 1));
	//	printf("TMP ISNEXTLINE: %s\n", *tmp);

	//	ft_strcpy(*stack, (*stack + len));

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
	char *buf;
	int r;
	char *tmp;
	static char *stack[MAX_FD];
	//

	if ((fd < 0 || line == NULL || read(fd, stack[fd], 0) < 0) || \
	!(buf = ft_strnew(sizeof(char) * BUFF_SIZE)))
		return (-1);
	printf("GNL BUF: %s\n", buf);
	if(stack[fd])
		if(ft_is_next_line(&stack[fd], line))
			//line = (char **)ft_strjoin(stack[fd], tmp);
			//printf("%s\n", *line);
			//free(tmp);
			return(1);
	while((r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[r] ='\0';
		if(stack[fd])
		{
			printf("read bytes: %d\n", r);
			tmp = stack[fd];
			stack[fd] = ft_strjoin(tmp, buf);
			free(tmp);
			tmp = NULL;
	//	printf("buf is: %s\n", buf);
	//	buf[0] = '\0';
			printf("GNL STACK: %s\n", stack[fd]);
		}
		else
		{
			stack[fd] = ft_strdup(buf);
			printf("GNL STACK[FD]: %s\n", stack[fd]);
			if (ft_is_next_line(&stack[fd], line))
				break ;
			//line = (char **)ft_strjoin(stack, buf);
		}
}
free (buf);

		return(0);
	//	buf[r] = '\0';
	// }
	// //	printf("%d\n %s\n", r, buf);
	// return(0);
}
