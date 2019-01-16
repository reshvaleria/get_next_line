#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int g;
if (argc)
{
g = 1;
	int fd;
 	char *line;
//char buf[2];
	// g = 1;
	 fd = open(argv[1], O_RDONLY);
	while (g > 0)
	{
		g = get_next_line(fd, &line);
		printf("line: %s\n", line);
		free(line);
	}
	//get_next_line(fd, &line);
	//printf("THIS IS FINAL LINE: %s\n", line);
	free(line);
	}
//printf("%d",read(fd, buf, 0));
}
