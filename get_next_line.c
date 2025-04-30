/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: navera-m <navera-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:57:25 by navera-m          #+#    #+#             */
/*   Updated: 2025/04/30 15:10:04 by navera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_break_in_line(char *storage)
{
	char		*tmp;
	int			size;
	int			i;

	size = 0;
	i = 0;
	while (storage[size] != '\0' && storage[size] != '\n')
		size++;
	if (storage[size] == -1 || storage[0] == '\0')
		return (storage);
	size++;
	tmp = ft_calloc(size + 1, sizeof(char));
	if (!tmp)
		return (NULL);
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
	char	*temp_string;
	size_t	i;

	i = 0;
	if (!storage[i] || storage[i] == '\0')
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	temp_string = ft_calloc((i + 2), sizeof(char));
	if (!temp_string)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		temp_string[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{
		temp_string[i] = storage[i];
		i++;
	}
	return (temp_string);
} */
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
		str = ft_calloc(2, sizeof(char));
	if (!str)
		return (NULL);
	i = 1;
	tmp = ft_calloc(BUFFER_SIZE + 2, sizeof(char));
	if (!tmp)
		return (NULL);
	while (i != 0 && ft_gnl_strchr(str, '\n') != 1)
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i >= 0)
			tmp[i] = '\0';
		if (i == 0 && str[0] == '\0')
			return (free(tmp), free (str), NULL);
		if (i < 0)
			return (free(tmp), free(str), NULL);
		str = ft_strjoin(str, tmp);
	}
	free(tmp);
	return (str);
}

char	*ft_update_bufffer(char *b)
{
	char	*temp_string;
	int		start;
	int		i;

	start = 0;
	i = 0;
	while (b[start] != '\0' && b[start] != '\n')
		start++;
	if (!b[start])
		return (free(b), NULL);
	temp_string = ft_calloc((ft_strlen(b) - start + 1), sizeof(char));
	if (!temp_string)
		return (NULL);
	start++;
	while (b[start] && b[start] != '\0')
		temp_string[i++] = b[start++];
	free(b);
	return (temp_string);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = ft_reader(fd, storage);
	if (!storage)
		return (free(storage), NULL);
	line = ft_break_in_line(storage);
	if (*line == 0)
		return (NULL);
	storage = ft_update_bufffer(storage);
	return (line);
}
