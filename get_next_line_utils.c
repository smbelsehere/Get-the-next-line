/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: navera-m <navera-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:59:07 by navera-m          #+#    #+#             */
/*   Updated: 2025/04/25 15:49:18 by navera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_gnl_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p != '\0')
	{
		if (*p == (char)c)
			return (1);
		p++;
	}
	if (*p == (char)c)
		return (1);
	
	return (0);
}
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;
	int	size;
	int	i;
	int	j;
	size = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	s3 = malloc (sizeof(char) * size);
	if (!s3)
	return (NULL);
	i = 0;
	while (ft_strlen(s1) > i && s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (ft_strlen(s2) > j && s2[j] != '\0' && j < 10)
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}
void	ft_bzero(void *s, int n)
{
	int			i;
	unsigned char	*l;

	i = 0;
	l = (unsigned char *)s;
	while (i < n)
	{
		l[i] = '\0';
		i++;
	}
}
void	*ft_calloc(int nmemb, int size)
{
	unsigned char	*p;

	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, (nmemb * size));
	return (p);
}
