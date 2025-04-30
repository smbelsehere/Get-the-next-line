/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: navera-m <navera-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:59:11 by navera-m          #+#    #+#             */
/*   Updated: 2025/04/30 15:10:19 by navera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_strlen(const char *s);
int		ft_gnl_strchr(char *s, int c);
char	*ft_strjoin(char *s1, const char *s2);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_break_in_line(char *storage);
char	*ft_reader(int fd, char *str);
char	*get_next_line(int fd);
void	ft_bzero(void *s, int n);

#endif