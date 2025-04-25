/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: navera-m <navera-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:59:04 by navera-m          #+#    #+#             */
/*   Updated: 2025/04/25 15:42:23 by navera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int			fd;
	char	*line;
	int		counter;

	int i = 0;
	counter = 0;
	fd = open("test.txt", O_RDONLY);
	//line = get_next_line(fd);
	//line = get_next_line(fd);
	/* while (line != NULL && i++ < 5) */
	while (i++ < 8)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("[%d]%s", i, line);
		//free(line);
	}
	close(fd);
}
