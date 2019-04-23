#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int g;
	int fd;
	char *line;

	if (argc)
	{
		g = 1;

		fd = open(argv[1], O_RDONLY);
		while (g > 0)
		{
			g = get_next_line(fd, &line);
			printf("%s\n", line);
			ft_strdel(&line);
		}
		close(fd);
	}
}
