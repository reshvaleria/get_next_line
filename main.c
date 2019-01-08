#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int g;
	int fd;
 	char *line;
//char buf[2];
	// g = 1;
	 fd = open(argv[1], O_RDONLY);
	// while (g > 0)
	// {
	// 	g = get_next_line(fd, &line);
	// 	printf("line: %s\n", line);
	// 	free(line);
	// }
	get_next_line(fd, &line);
//printf("%d",read(fd, buf, 0));
}
