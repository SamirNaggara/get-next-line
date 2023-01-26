/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:22:25 by snaggara          #+#    #+#             */
/*   Updated: 2023/01/26 13:10:46 by snaggara         ###   ########.fr       */
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




char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	if (len == 0)
		return ((char *)0);
	j = 0;
	while (big[j])
	{
		if (big[j] == *little)
		{
			i = 0;
			while (little[i] && big[j + i] == little[i] && i + j < len)
				i++;
			if (!little[i])
				return ((char *)(big + j));
		}
		j++;
	}
	return ((char *)0);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	if ((!dest || !src) && size == 0)
		return (0);
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (!src || size <= dest_len)
		return (size + src_len);
	i = 0;
	while (src[i] && dest_len + i < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	if (size <= dest_len)
		dest_len = size;
	return (dest_len + src_len);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*srcbis;
	char	*destbis;

	srcbis = (void *)src;
	destbis = (void *)dest;
	if (!srcbis && !destbis)
		return (destbis);
	if (srcbis >= destbis)
		ft_move_sens1(destbis, srcbis, n);
	else
	{
		i = n - 1;
		while (i + 1 != 0)
		{
			destbis[i] = srcbis[i];
			i--;
		}
	}
	return (destbis);
}

void	ft_move_sens1(char *destbis, char *srcbis, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		destbis[i] = srcbis[i];
		i++;
	}
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	ft_memset(result, 0, size + 1);
	ft_strlcat(result, s1, ft_strlen(s1) + 1);
	ft_strlcat(result, s2, size + 1);
	return (result);
}
