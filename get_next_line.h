/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:29:30 by snaggara          #+#    #+#             */
/*   Updated: 2022/12/29 18:31:51 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_data_line
{
	int				length_line;
}t_data_line;
typedef struct s_static {
	char	buffer[BUFFER_SIZE + 1];
	int		cursor_beg;
	int		cursor_end;
	int		nb_octet;
}t_static;

char		*get_next_line(int fd);
char		*ft_strdup(const char *s);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *s, int c, size_t n);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
int			get_length_line_buffer(struct s_static *data_static);
t_static	*define_static(int fd);
char		*free_data_static(t_static *data_static);
char		*free_line_and_static(t_static *data_static,
				t_data_line *data_line);

#endif
