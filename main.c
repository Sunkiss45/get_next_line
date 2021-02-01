#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int     main(int argc, char **argv)
{
	int		fd;
	int		ret = 0;
	char	*str;
	int		n = 1000;
	int		x = 1;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	printf("\n(( %d ))\n", fd);
	while(n-- > 0 && (ret = get_next_line(fd, &str)) == 1)
	{
		printf("l-[%d]: [%s]\n", x, str);
		x++;
		free(str);
	}
	printf("\nRETOUR GNL = %d\nTOUR = %d\n", ret, x);
	close(fd);
}
