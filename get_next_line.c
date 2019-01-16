/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:56:18 by wjeyne-d          #+#    #+#             */
/*   Updated: 2019/01/16 21:26:41 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	ft_is_next_line(char **stack, char **line)
{
	char *ptr;
	char *tmp;

	printf("stroka v kotoroi ischem perenos: %s\n", *stack);
	if ((ptr = ft_strchr(*stack, '\n')))
	{
		printf("PTR ISNEXTLINE: %s\n", ptr);
		tmp = &*ptr;
		printf("TMP CHAR ISNEXTLINE: %c!\n", *tmp);
		*tmp = '\0';
		printf("TMP CHAR ISNEXTLINE (should be '0'): %c!\n", *tmp);
		*line = ft_strdup(*stack);
		*stack = ft_strdup(tmp + 1);
		return (1);
	}
	printf("strchr didnt found perenos stroki\n");
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	char *buf;
	int r;
	char *tmp;
	static char *stack[MAX_FD];

	if ((fd < 0 || fd > MAX_FD|| line == NULL || read(fd, stack[fd], 0) < 0)
	\|| !(buf = ft_strnew(sizeof(char) * BUFF_SIZE)))
		return (-1);
	if(stack[fd])
		if(ft_is_next_line(&stack[fd], line))
			return(1);
	while((r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[r] ='\0';
		if(stack[fd])
		{
			tmp = stack[fd];
			stack[fd] = ft_strjoin(tmp, buf);
			free(tmp);
			tmp = NULL;
		}
		else
			stack[fd] = ft_strdup(buf);
		if (ft_is_next_line(&stack[fd], line))
				break ;
	}
	if (r != 0 || stack[fd] == NULL || stack[fd][0] == '\0')
	{
		if (!r && *line)
			*line = NULL;
		return (r > 0 ? 1 : r);
	}
	*line = stack[fd];
	stack[fd] = NULL;
	return (1);
}
