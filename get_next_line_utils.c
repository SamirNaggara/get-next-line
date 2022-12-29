/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:22:25 by snaggara          #+#    #+#             */
/*   Updated: 2022/12/29 22:26:51 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	size;
	size_t	i;

	size = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	ft_memset(result, 0, size + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	return (result);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*sbis;

	sbis = (char *)s;
	i = 0;
	while (i < n)
	{
		sbis[i] = c;
		i++;
	}
	return (sbis);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (1);
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (1);
}

char	*free_line_and_static(t_static *data_static, t_data_line *data_line)
#include "get_next_line.h"
{
	free_data_static(data_static);
	free(data_line);
	return (NULL);
}
