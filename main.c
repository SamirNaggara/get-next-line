#include "get_next_line.h"

int	main()
{
	int 	fd;

	fd = open("test.txt", O_RDONLY);
	if (!fd)
		return (0);

	printf("The next line : %s\n", get_next_line(fd));
	printf("The next line : %s\n", get_next_line(fd));

}