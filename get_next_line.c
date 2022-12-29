/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:12:14 by snaggara          #+#    #+#             */
/*   Updated: 2022/12/29 22:44:32 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// V2
char	*get_next_line(int fd)
{
	static int			nb_line;
	static t_static		*data_static;
	char				*to_return;

	// Si le nombre de ligne est a 0
		// Definir le static


		// Ecrire dans le buffer de BUFFER_SIZE caractere
			// Si le buffer est null, retourne null
			// Si il y a un /n dans le buffer
				// Retourner la premiere ligne
				// Sauvegarder le reste dans une variable buff_memory
			// Si il n'y a pas de /n dans le buffer
				// Si le buffer est allée au bout (donc que nb_octet == BUFFER_SIZE)
					// Alors on lance le buffer encore
				// Si le buffer a envoyé une valeur plus petite que BUFFER_SIZE
					// ALors c'est la fin, on renvoie ce qu'il reste
					// On met la valuer is_finish sur 1
		
	// Si le nombre de ligne est supérieur à 0
		// Si buffer_memory est vide
			// On relance le buffer
			// Puis on relance le gros bloc d'avant qui rejette une ligne en fonction d'un buffer
		// S'il y a deja quelque chose dans buffer memory
			// On le met dans le buffer
				// On regarde s'il y a un /n dedans
					// S'il y a un /n dedans, on renvoie la ligne
					// Sauvegardant le reste dans buffer memory
				// S'il y a pas de /n dedans
					// On relance le buffer
					// On concatene ce qu'il y a dans buffer memory et le nouveau buffer
					// Puis on relance le gros bloc d'avant qui rejette une ligne en fonction d'un buffer




		
			
}

// Fonction qui renvoie l'occurence du premier \n qu'il trouve

static struct 
	buffer[BUFFER_SIZE]
	buffer_memory
	cursor 
	nb_octet_read
	is_finish






char	*get_next_line(int fd)
{
	static int			nb_line;
	static t_static		*data_static;
	t_data_line			*data_line;
	char				*to_return;

	if (!nb_line)
		data_static = define_static(fd);
	if (!data_static)
		return (NULL);
	// printf("Le buffer : %s\n", data_static->buffer);
	// printf("Le buffer : %c\n", data_static->buffer[0]);
	// printf("Les nombre total d'octets : %d\n", data_static->nb_octet);
	
	if ((data_static->nb_octet == 1 && (
			data_static->buffer[0] == '\n'
			|| data_static->buffer[0] == '\r')))
		{			
			free_data_static(data_static);
			to_return = (char *)malloc(sizeof(char) * 2);
			to_return[0] = '\n';
			to_return[1] = '\0';
			return (to_return);
		}
	if (data_static->cursor_beg >= data_static->nb_octet)
		return (free_data_static(data_static));
	data_line = (t_data_line *)malloc(sizeof(t_data_line));
	if (!data_line)
		return (free_data_static(data_static));
	data_line->length_line = get_length_line_buffer(data_static);
	to_return = (char *)malloc(sizeof(char) * (data_line->length_line + 2));
	if (!to_return)
		free_line_and_static(data_static, data_line);
	ft_memset(to_return, 0, data_line->length_line + 1);
	//printf("Le buffer : %s\n", data_static->buffer);
	//printf("a longueur de la ligne : %d\n", data_line->length_line);

	ft_strlcpy(to_return, data_static->buffer
		+ data_static->cursor_beg, data_line->length_line + 1);
	data_static->cursor_beg = data_static->cursor_end + 1;
	free(data_line);
	nb_line++;
	return (to_return);
}

// printf("Le buffer : %s\n", data_static->buffer);
// printf("Le buffer : %d\n", data_static->nb_octet);
// printf("Le buffer : %d\n", data_static->cursor_beg);
// printf("Le buffer : %d\n", data_static->cursor_end);
// printf("a longueur de la ligne : %d\n", data_line->length_line);

t_static	*define_static(int fd)
{
	static t_static	*data_static;

	data_static = (struct s_static *)malloc(sizeof(t_static));
	if (!data_static)
		return (NULL);
	
	data_static->nb_octet = read(fd, data_static->buffer, BUFFER_SIZE);
	if (data_static->nb_octet == -1)
	{
		free(data_static);
		return (NULL);
	}
	data_static->cursor_beg = 0;
	data_static->cursor_end = 0;
	return (data_static);
}

int	get_length_line_buffer(struct s_static *data_static)
{
	int		i;
	int		cursor;

	cursor = data_static->cursor_beg;
	i = 0;
	while (data_static->buffer[i] && cursor < data_static->nb_octet
		&& (data_static->buffer[cursor] != '\n'
			&& data_static->buffer[cursor] != '\r'))
	{
		i++;
		cursor++;
	}
	data_static->cursor_end = cursor;
	return (data_static->cursor_end - data_static->cursor_beg);
}

char	*free_data_static(t_static *data_static)
{
	free(data_static);
	return (NULL);
}
