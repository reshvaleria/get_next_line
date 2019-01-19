#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int g;
	int fd;
	char *line;
	int i;

	if (argc)
	{
		g = 1;
		i = 0;

		fd = open(argv[1], O_RDONLY);
		while (g > 0)
		{
			i++;
			g = get_next_line(fd, &line);
			printf("LINE: %s\n", line);
			free(line);
			//printf("%d\n", g);
		}
		close(fd);
	}
}
