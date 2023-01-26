/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:12:14 by snaggara          #+#    #+#             */
/*   Updated: 2023/01/26 03:26:06 by snaggara         ###   ########.fr       */
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
		ft_memset(data_static->buffer, 0, BUFFER_SIZE + 1);
		if (!data_static)
			return (NULL);
	}
	// Si le buffer est vide, on appelle read au max du buffer, on ajoute un \0 pour le plaiz
	if (ft_strlen(data_static->buffer) == 0)
	{
		data_static->nb_octet_lu = read(fd, data_static->buffer, BUFFER_SIZE);
		data_static->buffer[BUFFER_SIZE + 1] = '\0';
		if (data_static->nb_octet_lu == 0)
		{
			nb_line = 0;
			free(data_static);
			return (NULL);
		}
	}
	
	// On regarde si y'a un \n dans le buffer
	pos_end_line = ft_strnstr(data_static->buffer, "\n", BUFFER_SIZE);

	// Si y'a un \n, on renvoie tout ce qu'il y avant le \n, puis on déplace le buffer
	if (pos_end_line)
	{
		to_return = (char *)malloc(sizeof(char) * (pos_end_line - data_static->buffer + 1));
		if (!to_return)
			return (NULL);
		ft_memset(to_return, 0, pos_end_line - data_static->buffer + 1);
		ft_strlcpy(to_return, pos_end_line, pos_end_line - data_static->buffer + 1);
		ft_memmove(data_static->buffer, pos_end_line + 1, ft_strlen(pos_end_line + 1));
		return (to_return);
	}
	// La y'a pas de \n, soit parce que le buffer est plein
	if (ft_strlen(data_static->buffer) == BUFFER_SIZE)
	{
		to_return = ft_strdup(data_static->buffer);
		ft_memset(data_static->buffer, 0, BUFFER_SIZE + 1);
		return (to_return);	
	}

	// Ou alors le buffer est pas pleins, alors on va le remplir
	// On mettant dans le buffer local la longueur qu'il manque pour remplir le buffer
	ft_memset(buffer_local, 0, BUFFER_SIZE + 1);
	data_static->nb_octet_lu = read(fd, buffer_local, BUFFER_SIZE - ft_strlen(data_static->buffer));
	// Attends si on a rien lu, faut renvoyer tout le buffer
	if (data_static->nb_octet_lu == 0)
	{
		to_return = ft_strdup(data_static->buffer);
		ft_memset(data_static->buffer, 0, BUFFER_SIZE + 1);
		return (to_return);	
	}
	// Sinon, on a un buffer un peu plus remplie,
	// on concatene, puis on refait un tour de gnl pour voir si y'a un \n ou non
	ft_strlcat(data_static->buffer, buffer_local, BUFFER_SIZE + 1);
	nb_line--;
	return (get_next_line(fd));
	
}


