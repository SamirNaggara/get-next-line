#include "get_next_line.h"

int	main()
{
	int 	fd;
	char	*chaine;

	fd = open("test.txt", O_RDONLY);
	if (!fd)
		return (0);

	chaine = get_next_line(fd);
	printf("The next line : %s", chaine);
}