/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:29:30 by snaggara          #+#    #+#             */
/*   Updated: 2023/01/26 03:14:53 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>


typedef struct s_static {
	char	buffer[BUFFER_SIZE + 1];
	int		nb_octet_lu;
}t_static;

char		*get_next_line(int fd);
char		*ft_strdup(const char *s);
void		*ft_memset(void *s, int c, size_t n);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
char		*ft_strnstr(const char *big, const char *little, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_move_sens1(char *destbis, char *srcbis, size_t n);


#endif
