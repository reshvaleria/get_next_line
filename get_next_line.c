/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjeyne-d <wjeyne-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:56:18 by wjeyne-d          #+#    #+#             */
/*   Updated: 2019/01/16 23:01:59 by wjeyne-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_is_next_line(char **stack, char **line)
{
	char *ptr;
	char *tmp;

	if ((ptr = ft_strchr(*stack, '\n')))
	{
		tmp = ptr;
		*tmp = '\0';
		*line = ft_strdup(*stack);
		ft_strdel(stack);
		*stack = ft_strdup(tmp + 1);
		return (1);
	}
	return (0);
}

static	void	ft_stack_check(char **stack, char **buf)
{
	char *tmp;

	if (*stack)
	{
		tmp = *stack;
		*stack = ft_strjoin(tmp, *buf);
		ft_strdel(&tmp);
	}
	else
		*stack = ft_strdup(*buf);
}

static int ft_line_maker(int r, char **stack, char **line)
{
	if (r != 0 || *stack == NULL || *stack[0] == '\0')
	{
		if (!r && *line)
		{
			*line = NULL;
			ft_strdel(stack);
		}
		return (r > 0 ? 1 : r);
	}
	*line = *stack;
	*stack = NULL;
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char *stack[MAX_FD];
	char		*buf;
	int			r;

	if ((fd < 0 || fd > MAX_FD || !line || read(fd, stack[fd], 0) < 0)
		|| !(buf = ft_strnew(sizeof(char) * BUFF_SIZE)))
		return (-1);
	if (stack[fd])
		if (ft_is_next_line(&stack[fd], line))
			return (1);
	while ((r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[r] = '\0';
		ft_stack_check(&stack[fd], &buf);
		if (ft_is_next_line(&stack[fd], line))
		{
			free (buf);
			break ;
		}
	}
	return (ft_line_maker(r, &stack[fd], line));
}
