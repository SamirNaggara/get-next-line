/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:12:14 by snaggara          #+#    #+#             */
/*   Updated: 2022/12/29 05:09:04 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static int	nb_line;
	static t_static	*data_static;
	t_data_line	*data_line;
	char						*to_return;

	// Voila ce qu'il se passe QUE la première fois
	if (!nb_line)
	{
		// Malloc data_static
		data_static = (struct s_static *)malloc(sizeof(t_static));
		if (!data_static)
			return (NULL);
		// Lis tout le buffer, juste la premiere fois
		data_static->nb_octet = read(fd, data_static->buffer, BUFFER_SIZE + 1);
		if (data_static->nb_octet == -1)
		{
			free(data_static);
			return (NULL);
		}
		data_static->buffer[BUFFER_SIZE] = '\0'; 
		data_static->cursor_beg = 0;
		data_static->cursor_end = 0;
	}
	if (data_static->cursor_beg >= data_static->nb_octet)
	{
		free(data_static);
		return (NULL);
	}

	// Initialise la structure data line 
	data_line = (t_data_line *)malloc(sizeof(t_data_line));
	if (!data_line)
	{
		free(data_static);
		return (NULL);
	}



	// On va chercher la longueur du buffer
	data_line->length_line = get_length_line_buffer(data_static);

	to_return = (char *)malloc(sizeof(char) * (data_line->length_line + 1));
	if (!to_return)
	{
		free(data_line);
		free(data_static);
		return (NULL);
	}
	ft_memset(to_return, 0, data_line->length_line + 1);

	ft_strlcpy(to_return, data_static->buffer + data_static->cursor_beg, data_line->length_line + 1);


	//free(data_line);
	data_static->cursor_beg = data_static->cursor_end + 1;

	free(data_line);

	nb_line++;
	return (to_return);
}

int	get_length_line_buffer(struct s_static *data_static)
{
	int		i;
	int		cursor;

	cursor = data_static->cursor_beg;
	i = 0;
	while (data_static->buffer[i] && cursor < data_static->nb_octet &&
		(data_static->buffer[cursor] != '\n'
		&& data_static->buffer[cursor] != '\r'))
	{
		i++;
		cursor++;
	}
	data_static->cursor_end = cursor;
	return (data_static->cursor_end - data_static->cursor_beg);
}



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
	// chaine = get_next_line(fd);
	// printf("%s\n",chaine);
	// free(chaine);
	while (chaine)
	{
		printf("%s\n",chaine);
		free(chaine);
		chaine = get_next_line(fd);
	}

	close(fd);
}