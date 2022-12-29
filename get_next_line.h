
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include<stddef.h>
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
char 	*get_next_line(int fd);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int	get_length_line_buffer(struct s_static *data_static);

#endif

