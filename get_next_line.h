/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: navera-m <navera-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:59:11 by navera-m          #+#    #+#             */
/*   Updated: 2025/04/25 15:49:08 by navera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(const char *s);
int		ft_gnl_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_calloc(int nmemb, int size);
char	*ft_break_in_line(char *storage);
char	*ft_reader(int fd, char *str);
char	*get_next_line(int fd);
void	ft_bzero(void *s, int n);


#endif