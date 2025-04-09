/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: navera-m <navera-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:57:25 by navera-m          #+#    #+#             */
/*   Updated: 2025/04/09 13:17:01 by navera-m         ###   ########.fr       */
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
	while (storage[size] != '\n' || '\0')
		size++;
	tmp = ft_calloc(size + 1, sizeof(char));
	/* if (!tmp)
		free(tmp); */
	while (size > 0)
	{
		tmp[i] = *storage;
		i++;
		storage++;
		size--;
	}
	return (tmp);
}

char	*ft_reader(int fd, char *str)
{
	char	*tmp;
	int		i;

	if (!str)
		str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!tmp)
			return (NULL);
		i = read(fd, tmp, BUFFER_SIZE); /* leo y almaceno en tmp */
	//	printf("bytes read %d\n", i);
		if (i <= 0)
		{
			if (!str)
				return (free(tmp), NULL); // maybe not needed and instead break (if < 0 free str and if EOF return str)
		}
		str = ft_strjoin(str, tmp);
		//printf("str %s\n", str);
		//printf("found new line %d\n", ft_gnl_strchr(str, '\n'));
		if (ft_gnl_strchr(str, '\n') == 1)
			break ;
		free(tmp);
	}
	//printf("exit while \n");
	free(tmp); /* liberar memoria de tmp cuando ya no la necesito */
	return (str);
}

char	*get_next_line(int fd)
{
	static char *storage;
	char		*line; 

	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	/* if (!line)
		return (NULL); */
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = ft_reader(fd, storage);
	line = ft_break_in_line(storage);

	return (line);
}

/* Necesito extraer linea, liberar memoria */
