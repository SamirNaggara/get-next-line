#include "get_next_line.h"

int	main()
{
	int fd;
	char	*chaine;

	fd = open("test.txt", O_RDONLY);
	if (!fd)
		return (0);
	//printf("%s\n",get_next_line(fd));


	chaine = get_next_line(fd);
	// printf("%s\n",chaine);
	printf("%s", chaine);
	// chaine = get_next_line(fd);
	// printf("%s\n",chaine);
	// free(chaine);
	// while (chaine)
	// {
	// 	printf("%s\n",chaine);
	// 	free(chaine);
	// 	chaine = get_next_line(fd);
	// }
	// free(chaine);

	close(fd);
}