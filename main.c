/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: navera-m <navera-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:59:04 by navera-m          #+#    #+#             */
/*   Updated: 2025/04/30 12:31:01 by navera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int			fd;
	//int		counter;
	char	*line;

	int i = 0;
	//counter = 0;
	fd = open("empty.txt", O_RDONLY);
	//line = get_next_line(fd);
	//line = get_next_line(fd);
	/* while (line != NULL && i++ < 5) */
	line = get_next_line(fd);
	//free(line);
	while (line)
	{
		printf("[%d]%s", i, line);
		free(line);
		line = get_next_line(fd);
		//if (line == NULL)
		//	break ; 
		//free(line);
		i++;
	}
	free(line);
	close(fd);
}
