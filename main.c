#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
// #include <time.h>
//
// clock_t begin = clock();
int main(int argc, char **argv)
{
	int g;
	int fd;
	char *line;
//	int i;

	if (argc)
	{
		g = 1;
	//	i = 0;

		fd = open(argv[1], O_RDONLY);
		while (g > 0)
		{
			//i++;
			g = get_next_line(fd, &line);
			printf("LINE:%s", line);
			printf("\n!\n");
			ft_strdel(&line);
			//printf("%d\n", g);
		}
		close(fd);
// 		clock_t end = clock();
// double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
// printf("%f\n", time_spent);
	}
}
