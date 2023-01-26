/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:12:14 by snaggara          #+#    #+#             */
/*   Updated: 2023/01/26 13:49:34 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// V2
char	*get_next_line(int fd)
{
	static int			nb_line;
	static t_static		*data_static;
	char				*to_return;
	char				*pos_end_line;
	char				buffer_local[BUFFER_SIZE + 1];

	// Si c'est le premier appel, okidoki on créé le t_static et on initialialise le buffer
	nb_line++;

	if (nb_line == 1)
	{
		data_static = (t_static *)malloc(sizeof(t_static));
		if (!data_static)
			return (NULL);
		data_static->buffer = (char *)malloc(sizeof(char));
		if (!data_static->buffer)
			return (NULL);
		data_static->buffer[0] = '\0';
		data_static->nb_octet_lu = 0;
		ft_memset(buffer_local, 0, BUFFER_SIZE + 1);
	}
	//printf("regarde dans le buffer static : %s\n", data_static->buffer);

	// On regarde si dans le buffer actuel il y a un \n
	// Si oui, on envoie la partie qu'on peux et on met à jour le buffer
	pos_end_line = ft_strnstr(data_static->buffer, "\n", ft_strlen(data_static->buffer));
	if (pos_end_line)
	{
			*pos_end_line = '\0';
			to_return = ft_strdup(data_static->buffer);
			if (!to_return)
				return (NULL);
			free(data_static->buffer);
			data_static->buffer = ft_strdup(pos_end_line + 1);

			return (to_return);
	}

	// Si on arrive jusqu'ici, c'est que le buffer n'a pas de \n à l'intérieur
	// Alors il faut refaire un appel à read

	data_static->nb_octet_lu = read(fd, buffer_local, BUFFER_SIZE);
	buffer_local[BUFFER_SIZE + 1] = '\0';

	// Si on a rien lu, donc on est arrivé au bout
	// On renvoie juste ce qui est dans le buffer static
	if (data_static->nb_octet_lu == 0)
	{
		nb_line = 0;
		data_static->nb_octet_lu = 0;
		to_return = ft_strdup(data_static->buffer);
		free(data_static->buffer);
		free(data_static);
		return (to_return);
	}

	// Si on a lu quelque chose, on peut le joindre au buffer static !
	to_return = ft_strjoin(data_static->buffer, buffer_local);
	free(data_static->buffer);
	data_static->buffer = ft_strdup(to_return);
	free(to_return);

	// Maintenant qu'on l'a joint au buffer static, on peut refaire un tour

	return (get_next_line(fd));
	

}
