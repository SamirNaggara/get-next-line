/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:12:14 by snaggara          #+#    #+#             */
/*   Updated: 2022/12/29 01:28:10 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	static int	nb_line;
	static int	cursor;
	static int	nb_octet;
	t_data_line	*data_line;

	if (cursor > nb_octet)
		return (NULL);

	// Initialise la structure data line 
	data_line = (t_data_line *)malloc(sizeof(t_data_line));
	if (!data_line)
		return (NULL);


	// Voila ce qu'il se passe QUE la première fois
	if (!nb_line)
	{
		// Lis tout le buffer, juste la premiere fois
		nb_octet = read(fd, buffer, BUFFER_SIZE);
		if (nb_octet == -1)
		{
			free(data_line);
			return (NULL);
		}
		cursor = 0;
	}
	// On range la valeur trouvée dans la structure, pour y avoir accès dans les fonctions
	data_line->nb_octet = nb_octet;
	data_line->cursor = cursor;
	// On va chercher la longueur du buffer
	data_line->length_line = get_length_line_buffer(data_line, buffer);
	data_line->to_return = (char *)malloc(sizeof(char) * (data_line->length_line + 1));
	if (!data_line->to_return)
	{
		free(data_line);
		return (NULL);

	}
	ft_strlcpy(data_line->to_return, buffer + cursor, data_line->length_line + 1);
	cursor = data_line->cursor;
	free(data_line);
	cursor++;
	nb_line++;
	return (data_line->to_return);
}

int	get_length_line_buffer(t_data_line *data_line, char *buffer)
{
	int		i;

	i = 0;
	while (data_line->cursor < data_line->nb_octet &&
		(buffer[data_line->cursor] != '\n'
		&& buffer[data_line->cursor] != '\r'))
	{
		i++;
		data_line->cursor = data_line->cursor + 1;
	}
	return ((int)i);
}


int	main()
{
	int fd;
	char	*chaine;

	fd = open("test.txt", O_RDONLY);
	if (!fd)
		return (0);
	
	while (chaine = get_next_line(fd))
	{
		printf("%s\n",chaine);
		free(chaine);

	}

	close(fd);
}