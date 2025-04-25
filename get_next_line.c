/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: navera-m <navera-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:57:25 by navera-m          #+#    #+#             */
/*   Updated: 2025/04/25 15:43:15 by navera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // detele me

char	*ft_break_in_line(char *storage)
{
	char		*tmp;
	int			size;
	int			i;

	size = 0;
	i = 0;
	while (storage[size] != '\0' && storage[size] != '\n')
		size++;
	if (storage[size] == '\0')
		return (storage);
	size++;
	tmp = ft_calloc(size + 1, sizeof(char));
	while (size > 0)
	{
		tmp[i] = storage[i];
		i++;
		size--;
	}
	return (tmp);
}
/* char	*ft_break_in_line(char *storage)
{
	char		*tmp;
	int			size;
	int			i;

	size = 0;
	i = 0;
	if (ft_gnl_strchr(storage, '\n'))
		return (storage);
	while (storage[size] != '\0')
		size++;
	if ((storage[size] != '\n'))
		size++;
	free(storage); 
	tmp = ft_calloc(size + 1, sizeof(char));
	while (size > 0)
	{
		tmp[i] = *storage;
		i++;
		storage++;
		size--;
	}
	return (tmp);
} */

char	*ft_reader(int fd, char *str)
{
	char	*tmp;
	int		i;

	if (!str)
		str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 1;
	while (i > 0 && ft_gnl_strchr(str, '\n') != 1)
	{
		tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!tmp)
			return (NULL);
		i = read(fd, tmp, BUFFER_SIZE);
		if (i < 0)
			return (free (str), NULL);
		str = ft_strjoin(str, tmp);
		if (i == 0)
			return (str);
		free(tmp);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char *storage;
	char		*line; 
	int			size;

	if (fd > 0 || BUFFER_SIZE > 0)
	{
		storage = ft_reader(fd, storage);
		if (!storage)
			return (NULL);
		line = ft_break_in_line(storage);
		if (*line == '\0')
			return (free(storage), NULL);
		size = ft_strlen(line);
		while (size-- > 0)
			storage++;
	}
	return (line);
}
