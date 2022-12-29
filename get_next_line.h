
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include<stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_data_line
{
	int				nb_octet;
	int				cursor;
	int				length_line;
	char			*to_return;
}t_data_line;

char 	*get_next_line(int fd);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlen(const char *str);
int	get_length_line_buffer(t_data_line *data_line, char *buffer);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif

